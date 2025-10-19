#include "../include/rectangle.h"
#include <cmath>

Rectangle::Rectangle(Point a, Point c) : p1(a), p3(c) {}

Point Rectangle::get_center() const {
    return {(p1.x + p3.x) / 2.0, (p1.y + p3.y) / 2.0};
}

Rectangle::operator double() const {
    // Находим две другие вершины, чтобы вычислить стороны
    Point p2 = {p1.x, p3.y};
    Point p4 = {p3.x, p1.y};
    double side1 = std::sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    double side2 = std::sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
    return side1 * side2;
}

// Реализация конструкторов и операторов
Rectangle::Rectangle(const Rectangle& other) : p1(other.p1), p3(other.p3) {}
Rectangle::Rectangle(Rectangle&& other) noexcept : p1(other.p1), p3(other.p3) {}
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) { p1 = other.p1; p3 = other.p3; }
    return *this;
}
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) { p1 = other.p1; p3 = other.p3; }
    return *this;
}

// Реализация операторов ввода/вывода
std::istream& operator>>(std::istream& is, Rectangle& r) {
    std::cout << "Enter 2 opposite vertices of a rectangle (x1 y1 x2 y2): ";
    is >> r.p1.x >> r.p1.y >> r.p3.x >> r.p3.y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    Point p2 = {r.p1.x, r.p3.y};
    Point p4 = {r.p3.x, r.p1.y};
    os << "Rectangle vertices: " << r.p1 << ", " << p2 << ", " << r.p3 << ", " << p4;
    return os;
}