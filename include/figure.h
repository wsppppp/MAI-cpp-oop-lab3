#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;

    // Чисто виртуальные методы, которые должны реализовать наследники
    virtual double getArea() const = 0;
    virtual operator double() const = 0;

    // Общие методы
    Point getCenter() const;

protected:
    // Данные, доступные наследникам
    int n;       // Количество вершин
    Point *p;    // Указатель на массив вершин

    // Дружественные операторы для доступа к protected-данным
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
};