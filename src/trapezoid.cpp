#include "../include/trapezoid.h"
#include <stdexcept>
#include <cmath>

Trapezoid::Trapezoid() {
    n = 4;
    p = new Point[n];
}
    const double EPS = 1e-6;

// будем считать, что одинаковый y для ||
Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    bool p1p2_parallel = std::abs(p1.y - p2.y) < EPS;
    bool p3p4_parallel = std::abs(p3.y - p4.y) < EPS;

    if (!p1p2_parallel || !p3p4_parallel) {
        throw std::logic_error("This is not a trapezoid.");
    }
    
    n = 4;
    p = new Point[n];
    p[0] = p1; p[1] = p2; p[2] = p3; p[3] = p4;
}

Trapezoid::~Trapezoid() {
    delete[] p;
    p = nullptr;
}

double Trapezoid::getArea() const {
    double base1 = p[0].length(p[1]);
    double base2 = p[2].length(p[3]);
    double height = std::abs(p[0].y - p[3].y);
    return (base1 + base2) * height / 2.0;
}

Trapezoid::operator double() const {
    return getArea();
}