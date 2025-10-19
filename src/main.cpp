#include "../include/figure.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/rhombus.h"
#include <vector>
#include <string>
#include <memory>

void print_menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add figure\n";
    std::cout << "2. Print all figures info\n";
    std::cout << "3. Calculate total area\n";
    std::cout << "4. Delete figure by index\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;

    do {
        print_menu();
        std::cin >> choice;

        // TODO: Реализовать логику для каждого пункта меню
        // Например, для '1': спросить тип фигуры, создать (new Rectangle),
        // прочитать данные (std::cin >> *figure), добавить в вектор.

    } while (choice != 5);

    return 0;
}