#pragma once
#include "figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    ~Rhombus();

    double getArea() const override;
    operator double() const override;

    Rhombus& operator=(const Rhombus& other);
    bool operator==(const Rhombus& other) const;
};