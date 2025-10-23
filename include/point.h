#pragma once
#include <iostream>
#include <cmath> // Используем cmath вместо math.h для C++

class Point {
public:
    // Конструкторы
    Point();
    Point(double x, double y);
    
    // Операторы
    Point& operator=(const Point& other);

    // Методы
    double length(const Point& other) const;
    bool is_equal(const Point& other) const;

    // Данные
    double x;
    double y;

    // Дружественные функции для операторов
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};