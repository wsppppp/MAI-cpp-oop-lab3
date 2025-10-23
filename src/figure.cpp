#include "../include/figure.h"

// читаем n точек
std::istream& operator>>(std::istream& is, Figure& figure) {
    std::cout << "Enter " << figure.n << " vertices for the figure:\n";
    for (int i = 0; i < figure.n; i++) {
        std::cout << "Point " << i + 1 << ": ";
        is >> figure.p[i];
    }
    return is;
}

// все точки из p
std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    for (int i = 0; i < figure.n; i++) {
        os << figure.p[i] << " ";
    }
    return os;
}

Point Figure::getCenter() const {
    double x_sum = 0, y_sum = 0;
    for (int i = 0; i < n; i++) {
        x_sum += p[i].x;
        y_sum += p[i].y;
    }
    return Point(x_sum / n, y_sum / n);
}