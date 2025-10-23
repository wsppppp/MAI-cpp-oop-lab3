#pragma once
#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    ~Rectangle();

    double getArea() const override;
    operator double() const override;
};