#include <iostream>

// Абстрактный класс "Фигура"
class Shape {
public:
    // Чисто виртуальная функция для вычисления площади фигуры
    virtual double area() const = 0;

    // Виртуальный деструктор
    virtual ~Shape() {}
};

// Конкретный класс "Квадрат", который наследуется от абстрактного класса "Фигура"
class Square : public Shape {
private:
    double side;

public:
    // Конструктор
    Square(double s) : side(s) {}

    // Реализация метода area() для квадрата
    double area() const override {
        return side * side;
    }
};

// Конкретный класс "Круг", который наследуется от абстрактного класса "Фигура"
class Circle : public Shape {
private:
    double radius;

public:
    // Конструктор
    Circle(double r) : radius(r) {}

    // Реализация метода area() для круга
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Функция для вывода площади фигуры
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    // Создание объектов квадрата и круга
    Square square(5.0);
    Circle circle(3.0);

    // Вызов функции для вывода площади фигуры
    printArea(square);
    printArea(circle);

    return 0;
}
