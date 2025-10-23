#include "../include/point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

std::istream& operator>>(std::istream& is, Point& p) {
    std::cout << "Enter X and Y: ";
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

bool Point::is_equal(const Point& other) const {
    const double EPS = 1e-6;
    return std::abs(this->x - other.x) < EPS && std::abs(this->y - other.y) < EPS;
}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

double Point::length(const Point& other) const {
    return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
}