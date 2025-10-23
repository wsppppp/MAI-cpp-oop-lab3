#pragma once
#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    ~Trapezoid();

    double getArea() const override;
    operator double() const override;
};