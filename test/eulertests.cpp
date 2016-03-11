#include <gtest/gtest.h>

// Project Euler solution headers
#include "projecteuler/pe1.h"
#include "projecteuler/pe2.h"
#include "projecteuler/pe3.h"
#include "projecteuler/pe4.h"
#include "projecteuler/pe5.h"

TEST(ProjectEulerTest, PE1) {
    EXPECT_EQ(233168, pe1());
}

TEST(ProjectEulerTest, PE2) {
    EXPECT_EQ(4613732, pe2());
}

TEST(ProjectEulerTest, PE3) {
    EXPECT_EQ(6857, pe3());
}

TEST(ProjectEulerTest, PE4) {
    EXPECT_EQ(906609, pe4());
}

TEST(ProjectEulerTest, PE5) {
    EXPECT_EQ(232792560, pe5());
}

// Run tests
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
