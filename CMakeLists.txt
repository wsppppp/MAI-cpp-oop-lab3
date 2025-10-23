# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.16)

# Задаём имя проекта для 3-й лабораторной работы
project(oop_lab_3)

# Устанавливаем стандарт C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==== Библиотека с фигурами ====
# Собираем всю логику фигур в одну статическую библиотеку 'figures'
add_library(figures
    src/point.cpp 
    src/figure.cpp
    src/figure_array.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
)
# Указываем, что заголовочные файлы для этой библиотеки лежат в папке 'include'
# PUBLIC означает, что все, кто подключает 'figures', автоматически получают доступ к 'include'
target_include_directories(figures PUBLIC include)

# ==== Основное приложение ====
# Главный исполняемый файл для демонстрации
add_executable(app src/main.cpp)
# Линкуем основное приложение с нашей библиотекой фигур
target_link_libraries(app PRIVATE figures)

# ==== Подключение GoogleTest для тестирования ====
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# ==== Тесты ====
# Создаём исполняемый файл для тестов
add_executable(run_tests tests/test_figures.cpp)
# Линкуем тесты с GoogleTest (gtest_main) и нашей библиотекой фигур
target_link_libraries(run_tests PRIVATE gtest_main figures)
# Добавляем тест в CTest
add_test(NAME unit_tests COMMAND run_tests)