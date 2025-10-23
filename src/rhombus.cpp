#include "../include/rhombus.h"
#include <stdexcept>
#include <cmath>

Rhombus::Rhombus() {
    n = 4;
    p = new Point[n];
}

Rhombus::Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double side1 = p1.length(p2);
    double side2 = p2.length(p3);
    double side3 = p3.length(p4);
    double side4 = p4.length(p1);
    const double EPS = 1e-6;

    // все стороны равны 
    if (std::abs(side1 - side2) > EPS || std::abs(side2 - side3) > EPS || std::abs(side3 - side4) > EPS) {
        throw std::logic_error("This is not a rhombus");
    }
    // проверяем, что диагонали не равны нулю
    if (p1.length(p3) < EPS || p2.length(p4) < EPS) {
        throw std::logic_error("This is not a rhombus");
    }
    
    n = 4;
    p = new Point[n];
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
}

Rhombus::~Rhombus() {
    delete[] p;
    p = nullptr;
}

double Rhombus::getArea() const {
    double d1 = p[0].length(p[2]);
    double d2 = p[1].length(p[3]);
    return (d1 * d2) / 2.0;
}

Rhombus::operator double() const {
    return getArea();
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        for (int i = 0; i < n; ++i) {
            p[i] = other.p[i];
        }
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    return static_cast<double>(*this) == static_cast<double>(other);
}