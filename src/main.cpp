#include <iostream>
#include "../include/figure_array.h"
#include "../include/rhombus.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"

int main() {
    FigureArray* figures = create_array();

    std::cout << "--- Adding figures ---\n";
    try {
        // 1. Создаем Ромб
        Figure* r1 = new Rhombus();
        std::cout << "Enter Rhombus:\n";
        std::cin >> *r1;
        add_figure(figures, r1);

        // 2. Создаем Прямоугольник
        Figure* rect1 = new Rectangle();
        std::cout << "\nEnter Rectangle:\n";
        std::cin >> *rect1;
        add_figure(figures, rect1);

        // 3. Создаем Трапецию (НОВОЕ)
        Figure* trap1 = new Trapezoid();
        std::cout << "\nEnter Trapezoid:\n";
        std::cin >> *trap1;
        add_figure(figures, trap1);

    } catch (const std::exception& e) {
        std::cerr << "Error during figure creation: " << e.what() << '\n';
    }

    std::cout << "\n--- All figures in array ---\n";
    for (int i = 0; i < figures->size; ++i) {
        // Получаем указатель на текущую фигуру для удобства
        Figure* fig = figures->figures[i];
        
        // Выводим всю информацию: Вершины, Центр, Площадь (ИЗМЕНЕНО)
        std::cout << "Figure " << i << ": " << *fig 
                  << " Center: " << fig->getCenter() 
                  << " Area: " << fig->getArea() << "\n";
    }

    std::cout << "\nTotal area: " << total_area(figures) << "\n";

    std::cout << "\n--- Removing figure at index 1 (the rectangle) ---\n";
    if (figures->size > 1) {
        remove_figure(figures, 1);
    }

    std::cout << "\n--- Figures after removal ---\n";
    for (int i = 0; i < figures->size; ++i) {
        Figure* fig = figures->figures[i];
        std::cout << "Figure " << i << ": " << *fig
                  << " Center: " << fig->getCenter()
                  << " Area: " << fig->getArea() << "\n";
    }

    // Очистка оставшихся фигур в цикле
    for (int i = 0; i < figures->size; ++i) {
        delete figures->figures[i];
    }
    // Очистка самой структуры массива
    destroy_array(figures);

    std::cout << "\nProgram finished.\n";
    return 0;
}


