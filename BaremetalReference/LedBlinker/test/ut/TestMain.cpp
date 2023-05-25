// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------

#include "Tester.hpp"

TEST(Nominal, ToDo) {
    BaremetalReference::Tester tester;
    tester.toDo();
}

TEST(Nominal, TestBlinking) {
    BaremetalReference::Tester tester;
    tester.testBlinking();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
