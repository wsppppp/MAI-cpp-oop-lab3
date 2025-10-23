#include "../include/figure_array.h"
#include <stdexcept>

FigureArray* create_array(int cap) {
    FigureArray* fa = new FigureArray;
    fa->cap = cap;
    fa->size = 0;
    fa->figures = new Figure*[cap];
    return fa;
}

// удаляем массив, а фигуры остаются 
void destroy_array(FigureArray* arr) {
    delete[] arr->figures;
    delete arr;
}

void add_figure(FigureArray* arr, Figure* fig) {
    if (arr->size == arr->cap) {
        int new_cap = arr->cap * 2;
        Figure** new_figures = new Figure*[new_cap];
        for (int i = 0; i < arr->size; ++i) {
            new_figures[i] = arr->figures[i];
        }
        delete[] arr->figures;
        arr->figures = new_figures;
        arr->cap = new_cap;
    }
    arr->figures[arr->size++] = fig;
}

void remove_figure(FigureArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        throw std::out_of_range("Index out of range.");
    }
    delete arr->figures[index];
    // сдвигаем
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