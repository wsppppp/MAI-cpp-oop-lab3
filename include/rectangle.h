#pragma once
#include "figure.h"

class Rectangle : public Figure {
private:
    Point p1, p3; // противоположные углы 

public:
    Rectangle() = default;
    Rectangle(Point a, Point c);

    Point get_center() const override;
    operator double() const override;

    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    // друзья для доступа к p1 и p3
    friend std::istream& operator>>(std::istream& is, Rectangle& r);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
};