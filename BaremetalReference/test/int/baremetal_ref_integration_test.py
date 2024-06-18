""" baremetal_ref_integration_test.py:

A set of integration tests to apply to the Baremetal Ref app. This is intended to be a reference of integration testing.
"""
import subprocess
import time
from enum import Enum
from pathlib import Path

from fprime_gds.common.testing_fw import predicates
from fprime_gds.common.utils.event_severity import EventSeverity

def test_send_command(fprime_test_api):
    """Test that commands can be sent

    Tests command send, dispatch, and receipt using a pair of NO_OP commands.
    """
    result = fprime_test_api.send_command('cmdDisp.CMD_NO_OP')
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_and_assert_command("cmdDisp.CMD_NO_OP", max_delay=10.0)
    #Note: send_and_assert_command has issues finding both displatched and completed EVRs. It can only find them if you
    #      send the same command twice. This is only an issue with baremetal due to not having a reference time and
    #      sclk from 0. Usage of send_command with assert_event has no issues and this test is an example of doing both.

def test_send_command_with_args(fprime_test_api):
    """Test that commands with arguments can be sent

    Test command send, dispatch, and receipt using a pair of NO_OP_STRING commands.
    """
    result = fprime_test_api.send_command('cmdDisp.CMD_NO_OP_STRING', ['hello'])
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_and_assert_command('cmdDisp.CMD_NO_OP_STRING', ['hola'], max_delay=10.0)

def test_telemetry_update(fprime_test_api):
    """Test that telemetry updates

    Test telemetry update using CMD_NO_OP command and CommandsDispatched channel.
    1. Send CMD_NO_OP and capture current value of CommandsDispatched as baseline.
    2. Send 5 CMD_NO_OP commands.
    3. Verify channel CommandsDispatched is the baseline value +5.
    """
    result = fprime_test_api.send_command('cmdDisp.CMD_NO_OP') #have to send a no op to get chan to update to grab baseline value
    result = fprime_test_api.await_telemetry('cmdDisp.CommandsDispatched')

    baselineVal = result.get_val() #await_telemetry() returns ChData and need to use the getter to get channel value.
    cmdsCount = 5
    expectedVal = baselineVal + cmdsCount

    for i in range(cmdsCount):
        result = fprime_test_api.send_command('cmdDisp.CMD_NO_OP')
    time.sleep(3)
    result = fprime_test_api.assert_telemetry('cmdDisp.CommandsDispatched', expectedVal, timeout = 5)

def test_event_filter(fprime_test_api):
    """Test that events can be filtered by type

    Test event filter with BLINKIING_ON_OFF command and associated activity hi EVR SetBlinkingState.
    1. Verify BLINKING_ON_OFF command and all associated EVRs are sent / nominal.
    2. Send SET_EVENT_FILTER command to disable activity hi evrs.
    3. Send BLINKING_ON_OFF command and verify SetBlinkingState evr, which is an activity hi evr, is filtered.
    4. Re-enable activity hi evrs and send BLINKING_ON_OFF back to on, verify evr is no longer filtered.
    """
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['ON'])
    result = fprime_test_api.assert_event('SetBlinkingState', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('eventLogger.SET_EVENT_FILTER', ['ACTIVITY_HI', 'DISABLED'])
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['OFF'])
    result = fprime_test_api.await_event_count(0, 'SetBlinkingState')
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    #tear down steps. set EVR back to enable and LED back to on.
    result = fprime_test_api.send_command('eventLogger.SET_EVENT_FILTER', ['ACTIVITY_HI', 'ENABLED'])
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['ON'])
    result = fprime_test_api.await_event_count(1, 'SetBlinkingState')
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')

def test_id_filter(fprime_test_api):
    """Test that event can be filtered by ID.

    Test ID filter with BLINKIING_ON_OFF command and associated activity hi EVR SetBlinkingState.
    1. Verify BLINKING_ON_OFF command and all associated EVRs are sent / nominal.
    2. Send SET_ID_FILTER command to filter SetBlinkingState EVR.
    3. Send BLINKING_ON_OFF command and verify SetBlinkingState EVR is filtered.
    4. Attempt to remove SetBlinkState evr again and verify that the SET_ID_FILTER command fails because ID is not found.
    5. Remove SetBlinkState EVR from the filter list  and send BLINKING_ON_OFF back to on.
    """
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['ON'])
    result = fprime_test_api.assert_event('SetBlinkingState', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(5)
    result = fprime_test_api.send_command('eventLogger.SET_ID_FILTER', ['0x10001', 'ENABLED'])
    result = fprime_test_api.assert_event('eventLogger.ID_FILTER_ENABLED', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['ON'])
    result = fprime_test_api.await_event_count(0, 'SetBlinkingState')
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('eventLogger.SET_ID_FILTER', ['0x10001', 'DISABLED'])
    result = fprime_test_api.assert_event('eventLogger.ID_FILTER_REMOVED', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
    time.sleep(3)
    result = fprime_test_api.send_command('eventLogger.SET_ID_FILTER', ['0x100', 'DISABLED'])
    result = fprime_test_api.assert_event('eventLogger.ID_FILTER_NOT_FOUND', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeError')
    time.sleep(3)
    result = fprime_test_api.send_command('blinker.BLINKING_ON_OFF', ['ON'])
    result = fprime_test_api.await_event_count(1, 'SetBlinkingState')
    result = fprime_test_api.assert_event('OpCodeDispatched', timeout = 3)
    result = fprime_test_api.assert_event('OpCodeCompleted')
