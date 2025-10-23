#pragma once
#include "figure.h"

// Структура для хранения массива указателей на фигуры
struct FigureArray {
    Figure **figures;
    int size;
    int capacity;
};

// Функции для работы с массивом
FigureArray* create_array(int capacity = 10);
void destroy_array(FigureArray* arr);
void add_figure(FigureArray* arr, Figure* fig);
void remove_figure(FigureArray* arr, int index);
double total_area(const FigureArray* arr);