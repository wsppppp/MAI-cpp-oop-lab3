#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
    virtual Point get_center() const = 0;
    virtual operator double() const = 0; 

    virtual ~Figure() = default;

    // реализация через сравнение площадей и центров
    bool operator==(const Figure& other) const;
};

// перегузка для ввода и вывода
std::istream& operator>>(std::istream& is, Figure& f);
std::ostream& operator<<(std::ostream& os, const Figure& f);