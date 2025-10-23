#pragma once
#include "figure.h"

// массив указателй
struct FigureArray {
    Figure **figures;
    int size;
    int cap;
};


FigureArray* create_array(int cap = 10);
void destroy_array(FigureArray* arr);
void add_figure(FigureArray* arr, Figure* fig);
void remove_figure(FigureArray* arr, int index);
double total_area(const FigureArray* arr);