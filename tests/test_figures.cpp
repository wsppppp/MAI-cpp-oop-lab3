#include <gtest/gtest.h>
#include "rhombus.h" // Подключаем наш новый ромб
#include <vector>
#include <stdexcept>

// Тест на успешное создание объекта
TEST(RhombusTest, Creation) {
    // Координаты правильного ромба
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    
    // Проверяем, что конструктор НЕ выбрасывает исключение для правильных данных
    ASSERT_NO_THROW(Rhombus r(p1, p2, p3, p4));
}

// Тест на вычисление центра
TEST(RhombusTest, CenterCalculation) {
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    Rhombus r(p1, p2, p3, p4);

    // ИСПОЛЬЗУЕМ ПРАВИЛЬНОЕ ИМЯ МЕТОДА: getCenter()
    Point center = r.getCenter();
    
    ASSERT_NEAR(center.x, 0.0, 1e-6);
    ASSERT_NEAR(center.y, 0.0, 1e-6);
}

// Тест на вычисление площади
TEST(RhombusTest, AreaCalculation) {
    Point p1{1, 0}, p2{0, 2}, p3{-1, 0}, p4{0, -2};
    Rhombus r(p1, p2, p3, p4);
    
    // Площадь = (d1 * d2) / 2 = (2 * 4) / 2 = 4
    ASSERT_NEAR(r.getArea(), 4.0, 1e-6);
}

// Тест на создание с неверными данными
TEST(RhombusTest, InvalidCreation) {
    // Неправильные координаты (не ромб)
    Point p1{0, 0}, p2{1, 1}, p3{2, 2}, p4{3, 3};

    // Проверяем, что конструктор ВЫБРАСЫВАЕТ исключение std::logic_error
    ASSERT_THROW(Rhombus r(p1, p2, p3, p4), std::logic_error);
}

// Точка входа для GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}