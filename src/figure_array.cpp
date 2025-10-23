#include "../include/figure_array.h"
#include <stdexcept>

FigureArray* create_array(int capacity) {
    FigureArray* fa = new FigureArray;
    fa->capacity = capacity;
    fa->size = 0;
    fa->figures = new Figure*[capacity];
    return fa;
}

void destroy_array(FigureArray* arr) {
    // Важно: эта функция не удаляет сами фигуры, только массив указателей
    // и саму структуру. Фигуры нужно удалять отдельно.
    delete[] arr->figures;
    delete arr;
}

void add_figure(FigureArray* arr, Figure* fig) {
    if (arr->size == arr->capacity) {
        // Простое расширение массива (можно сделать сложнее)
        int new_capacity = arr->capacity * 2;
        Figure** new_figures = new Figure*[new_capacity];
        for (int i = 0; i < arr->size; ++i) {
            new_figures[i] = arr->figures[i];
        }
        delete[] arr->figures;
        arr->figures = new_figures;
        arr->capacity = new_capacity;
    }
    arr->figures[arr->size++] = fig;
}

void remove_figure(FigureArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        throw std::out_of_range("Index out of range.");
    }
    // Удаляем саму фигуру
    delete arr->figures[index];
    // Сдвигаем оставшиеся элементы
    for (int i = index; i < arr->size - 1; ++i) {
        arr->figures[i] = arr->figures[i + 1];
    }
    arr->size--;
}

double total_area(const FigureArray* arr) {
    double sum = 0;
    for (int i = 0; i < arr->size; ++i) {
        sum += arr->figures[i]->getArea();
    }
    return sum;
}