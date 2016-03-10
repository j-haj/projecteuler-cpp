#include <gtest/gtest.h>

// Project Euler solution headers
#include "projecteuler/pe1.h"
#include "projecteuler/pe2.h"

TEST(ProjectEulerTest, PE1) {
    EXPECT_EQ(233168, pe1());
}

TEST(ProjectEulerTest, PE2) {
    EXPECT_EQ(4613732, pe2());
}

// Run tests
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
