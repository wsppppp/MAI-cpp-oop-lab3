#include <gtest/gtest.h>
#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"
#include <stdexcept>

// --------- RHOMBUS TESTS ---------
TEST(RhombusTest, CreationValid) {
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    ASSERT_NO_THROW(Rhombus r(p1, p2, p3, p4));
}

TEST(RhombusTest, CreationInvalid) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 2}, p4{3, 3};
    ASSERT_THROW(Rhombus r(p1, p2, p3, p4), std::logic_error);
}

TEST(RhombusTest, AreaCenter) {
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    Rhombus r(p1, p2, p3, p4);
    ASSERT_NEAR(r.getArea(), 4.0, 1e-6);
    Point center = r.getCenter();
    ASSERT_NEAR(center.x, 0.0, 1e-6);
    ASSERT_NEAR(center.y, 0.0, 1e-6);
}

TEST(RhombusTest, EqualityAndAssignment) {
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    Rhombus r1(p1, p2, p3, p4);
    Rhombus r2(p1, p2, p3, p4);
    ASSERT_TRUE(r1 == r2);
    Rhombus r3;
    r3 = r1;
    ASSERT_TRUE(r3 == r1);
}

// --------- RECTANGLE TESTS ---------
TEST(RectangleTest, CreationValid) {
    Point p1{0, 0}, p2{4, 0}, p3{4, 2}, p4{0, 2};
    ASSERT_NO_THROW(Rectangle r(p1, p2, p3, p4));
}

TEST(RectangleTest, CreationInvalid) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 2}, p4{3, 3};
    ASSERT_THROW(Rectangle r(p1, p2, p3, p4), std::logic_error);
}

TEST(RectangleTest, AreaCenter) {
    Point p1{0, 0}, p2{4, 0}, p3{4, 2}, p4{0, 2};
    Rectangle r(p1, p2, p3, p4);
    ASSERT_NEAR(r.getArea(), 8.0, 1e-6);
    Point center = r.getCenter();
    ASSERT_NEAR(center.x, 2.0, 1e-6);
    ASSERT_NEAR(center.y, 1.0, 1e-6);
}

TEST(RectangleTest, EqualityAndAssignment) {
    Point p1{0, 0}, p2{4, 0}, p3{4, 2}, p4{0, 2};
    Rectangle r1(p1, p2, p3, p4);
    Rectangle r2(p1, p2, p3, p4);
    ASSERT_TRUE(r1 == r2);
    Rectangle r3;
    r3 = r1;
    ASSERT_TRUE(r3 == r1);
}

// --------- TRAPEZOID TESTS ---------
TEST(TrapezoidTest, CreationValid) {
    // Верхнее основание y=2, нижнее основание y=0
    Point p1{1, 2}, p2{4, 2}, p3{5, 0}, p4{0, 0};
    ASSERT_NO_THROW(Trapezoid t(p1, p2, p3, p4));
}

TEST(TrapezoidTest, CreationInvalid) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 2}, p4{3, 3};
    ASSERT_THROW(Trapezoid t(p1, p2, p3, p4), std::logic_error);
}

TEST(TrapezoidTest, AreaCenter) {
    Point p1{1, 2}, p2{4, 2}, p3{5, 0}, p4{0, 0}; // bases: 3, 5; height: 2
    Trapezoid t(p1, p2, p3, p4);
    double base1 = p1.length(p2); // 3
    double base2 = p3.length(p4); // 5
    double height = 2;
    double expected_area = (base1 + base2) * height / 2.0;
    ASSERT_NEAR(t.getArea(), expected_area, 1e-6);
    Point center = t.getCenter();
    ASSERT_NEAR(center.x, 2.5, 1e-6);
    ASSERT_NEAR(center.y, 1.0, 1e-6);
}

TEST(TrapezoidTest, EqualityAndAssignment) {
    Point p1{1, 2}, p2{4, 2}, p3{5, 0}, p4{0, 0};
    Trapezoid t1(p1, p2, p3, p4);
    Trapezoid t2(p1, p2, p3, p4);
    ASSERT_TRUE(t1 == t2);
    Trapezoid t3;
    t3 = t1;
    ASSERT_TRUE(t3 == t1);
}

// --------- POLYMORPHISM & BASE CLASS TESTS ---------
TEST(FigureTest, PolymorphicAreaAndCenter) {
    Figure* f1 = new Rhombus(Point{1,0}, Point{0,2}, Point{-1,0}, Point{0,-2});
    Figure* f2 = new Rectangle(Point{0,0}, Point{4,0}, Point{4,2}, Point{0,2});
    Figure* f3 = new Trapezoid(Point{1,2}, Point{4,2}, Point{5,0}, Point{0,0});
    ASSERT_NEAR(f1->getArea(), 4.0, 1e-6);
    ASSERT_NEAR(f2->getArea(), 8.0, 1e-6);
    ASSERT_NEAR(f3->getArea(), 8.0, 1e-6);
    Point c1 = f1->getCenter();
    ASSERT_NEAR(c1.x, 0.0, 1e-6);
    ASSERT_NEAR(c1.y, 0.0, 1e-6);
    Point c2 = f2->getCenter();
    ASSERT_NEAR(c2.x, 2.0, 1e-6);
    ASSERT_NEAR(c2.y, 1.0, 1e-6);
    Point c3 = f3->getCenter();
    ASSERT_NEAR(c3.x, 2.5, 1e-6);
    ASSERT_NEAR(c3.y, 1.0, 1e-6);
    delete f1;
    delete f2;
    delete f3;
}

// --------- EDGE CASES ---------
TEST(RhombusTest, ZeroDiagonalThrows) {
    Point p1{0,0}, p2{0,0}, p3{0,0}, p4{0,0};
    ASSERT_THROW(Rhombus r(p1, p2, p3, p4), std::logic_error);
}

TEST(RectangleTest, DegenerateRectangleThrows) {
    Point p1{0, 0}, p2{0, 0}, p3{0, 0}, p4{0, 0};
    ASSERT_THROW(Rectangle r(p1, p2, p3, p4), std::logic_error);
}

TEST(TrapezoidTest, NonParallelBasesThrows) {
    Point p1{0, 0}, p2{1, 1}, p3{2, 2}, p4{3, 3};
    ASSERT_THROW(Trapezoid t(p1, p2, p3, p4), std::logic_error);
}

// --------- MAIN ---------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}