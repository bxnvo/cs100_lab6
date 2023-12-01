#include <gtest/gtest.h>

#include "../lib/testsubject.h"

TEST(MathTest, Square) {
    ASSERT_EQ(TestSubject::square(2), 4);
    
}

TEST(MathTest, Square2) {
    ASSERT_FALSE(TestSubject::square(3) == 9);
}

TEST(MathTest, Square3) {
    ASSERT_TRUE(TestSubject::square(5) == 10);
    
}

TEST(MathTest, isEven) {
    ASSERT_EQ(TestSubject::isEven(4), true);
}
TEST(MathTest, isEven2) {
    ASSERT_FALSE(TestSubject::isEven(9));
}
TEST(MathTest, isEven3) {
    ASSERT_TRUE(TestSubject::isEven(232));
}

