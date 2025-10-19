#pragma once
#include <iostream>

struct Point {
    double x, y;
};

std::istream& operator>>(std::istream& is, Point& p);
std::ostream& operator<<(std::ostream& os, const Point& p);