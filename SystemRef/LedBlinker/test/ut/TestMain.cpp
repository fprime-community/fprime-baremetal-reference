// ----------------------------------------------------------------------
// TestMain.cpp
// ----------------------------------------------------------------------

#include "Tester.hpp"

TEST(Nominal, ToDo) {
    SystemRef::Tester tester;
    tester.toDo();
}

TEST(Nominal, TestBlinking) {
    SystemRef::Tester tester;
    tester.testBlinking();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
