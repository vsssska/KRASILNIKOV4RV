#include <iostream>

// Абстрактный класс "Фигура"
class Shape {
public:
    // Чисто виртуальная функция для вычисления площади фигуры
    virtual double area() const = 0;

    // Перегрузка оператора вывода для фигуры
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        os << "Area: " << shape.area();
        return os;
    }

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

    // Перегрузка оператора вывода для квадрата
    friend std::ostream& operator<<(std::ostream& os, const Square& square) {
        os << "Square - " << square.area();
        return os;
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

    // Перегрузка оператора вывода для круга
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle) {
        os << "Circle - " << circle.area();
        return os;
    }
};

int main() {
    // Создание объектов квадрата и круга
    Square square(5.0);
    Circle circle(3.0);

    // Вывод площадей фигур с помощью перегруженного оператора вывода
    std::cout << square << std::endl;
    std::cout << circle << std::endl;

    return 0;
}
