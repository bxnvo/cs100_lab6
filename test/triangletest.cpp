#include "gtest/gtest.h"
#include "../lib/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) { //pass
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testPerimeter2) { //fail
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getPerimeter(),12);
}

TEST(TriangleTests, testPerimeter3) { //fail
    Triangle *aTriangle = new Triangle(6,4,3);
    EXPECT_FALSE (aTriangle->getPerimeter() == 13);
}

TEST(TriangleTests, testArea) { //fail
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getArea(),6);
}

TEST(TriangleTests, testArea2) { //pass
    Triangle *aTriangle = new Triangle(6,5,5);
    EXPECT_EQ (aTriangle->getArea(),12);
} //expect area (side 2 = side 3)

TEST(TriangleTests, testArea3) { //pass
    Triangle *aTriangle = new Triangle(6,5,5);
    EXPECT_TRUE (aTriangle->getArea() == 12);
} //expect area (side 2 = side 3)



TEST(TriangleTests, testIncorrectInput) { //pass
    //Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_DEATH (Triangle(3,4,5), "First side is not the longest");
}

TEST(TriangleTests, testCorrectInput) { // pass
    EXPECT_NO_THROW (Triangle(5,4,3));
}//expect not throw

TEST(TriangleTests, testInputInequality) { // pass
    EXPECT_DEATH (Triangle(6,4,1), "Does not satisfy triangle inequality");
}//expect not throw




TEST(TriangleTests, testIsIsoceles) { //fail
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->isIsosceles(),false);
}
TEST(TriangleTests, testIsIsoceles2) { //fail
    Triangle *aTriangle = new Triangle(4,3,3);
    EXPECT_EQ (aTriangle->isIsosceles(),true);
}
TEST(TriangleTests, testIsIsoceles3) { //fail
    Triangle *aTriangle = new Triangle(5,5,5);
    EXPECT_FALSE (aTriangle->isIsosceles());
}

TEST(TriangleTests, testIsEquilateral) { //pass
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->isEquilateral(),true);
}// expect equilateral
TEST(TriangleTests, testIsEquilateral2) { //pass
    Triangle *aTriangle = new Triangle(4,3,3);
    EXPECT_EQ (aTriangle->isEquilateral(),false);
}// expect equilateral
TEST(TriangleTests, testIsEquilateral3) { //pass
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_FALSE (aTriangle->isEquilateral());
}// expect equilateral



TEST(TriangleTests, testGetKind) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}
TEST(TriangleTests, testGetKind2) { // pass
    Triangle *aTriangle = new Triangle(4,3,3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::ISOSCELES);
}//expect kind
TEST(TriangleTests, testGetKind3) { // pass
    Triangle *aTriangle = new Triangle(4,3,2);
    EXPECT_TRUE (aTriangle->getKind() == Triangle::Kind::SCALENE);
}//expect kind



int main () {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}