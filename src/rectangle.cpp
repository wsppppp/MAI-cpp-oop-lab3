#include "../include/rectangle.h"
#include <stdexcept>
#include <cmath>

Rectangle::Rectangle() {
    n = 4;
    p = new Point[n];
}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    Point v1 = {p2.x - p1.x, p2.y - p1.y}; // в. -
    Point v2 = {p4.x - p1.x, p4.y - p1.y}; // л. |
    Point v3 = {p3.x - p2.x, p3.y - p2.y}; // н. -
    Point v4 = {p3.x - p4.x, p3.y - p4.y}; // п. |

    const double EPS = 1e-6; // погрешность для проверки
    // скалярное пр-ие = 0 
    if (std::abs(v1.x * v2.x + v1.y * v2.y) > EPS) {
        throw std::logic_error("This is not a rectangle: angle is not 90 degrees.");
    }
    // противополож равны
    if (!v1.is_equal(v4) || !v2.is_equal(v3)) {
         throw std::logic_error("This is not a rectangle: opposite sides are not equal.");
    }

    n = 4;
    p = new Point[n];
    p[0] = p1; p[1] = p2; p[2] = p3; p[3] = p4;
}

Rectangle::~Rectangle() {
    delete[] p;
    p = nullptr;
}

double Rectangle::getArea() const {
    double side1 = p[0].length(p[1]);
    double side2 = p[0].length(p[3]);
    return side1 * side2;
}

Rectangle::operator double() const {
    return getArea();
}