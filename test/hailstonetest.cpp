#include "gtest/gtest.h"
#include "../lib/Hailstone.h"

using sequence::satisfiesHailstone;

TEST(HailstoneTESTS,input1) {
    EXPECT_EQ (satisfiesHailstone(1),true);
}

TEST(HailstoneTESTS,input0) {
    EXPECT_FALSE (satisfiesHailstone(0));
}

TEST(HailstoneTESTS,inputEven) {
    EXPECT_TRUE (satisfiesHailstone(20));
}

TEST(HailstoneTESTS,inputOdd) {
    EXPECT_EQ (satisfiesHailstone(21),true);
}