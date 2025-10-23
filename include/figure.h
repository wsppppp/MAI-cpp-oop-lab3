#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;

    // наследники должны реализовать
    virtual double getArea() const = 0;
    virtual operator double() const = 0;

    Point getCenter() const;

protected:
    int n;// вершины
    Point *p; // указатель на массив вершин

    // други 
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
};