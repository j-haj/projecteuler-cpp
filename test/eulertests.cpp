#include <gtest/gtest.h>
#include "projecteuler/pe1.h"

TEST(ProjectEulerTest, PE1) {
    EXPECT_EQ(233168, pe1());
}

// Run tests
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
