#include <iostream>

class Shape { // abstract class - interface
public:
    virtual double area() = 0;
};

class Rectangle : public Shape { // concrete class - implementation
public:
    double base;
    double height;

    Rectangle(double base, double height) : base(base), height(height) {
        std::cout << "Rectangle constructor called" << std::endl;
    }
    // Rctangle class must implement the area() method, if not overridden then Rectangle will also be abstract class
    // You can't create an instance of abstract class
    double area() override {
        return base * height;
    }
};

class Triangle : public Shape { // concrete class - implementation
public:
    double base;
    double height;

    Triangle(double base, double height) : base(base), height(height) { // C++11 only - explicit keyword to avoid implicit conversion
        std::cout << "Triangle constructor called" << std::endl;
    }

//     Triangle class must implement the area() method if not overridden then Trianle will also be abstract class
    double area() override {
        return 0.5 * base * height;
    }
};

int main() {

    Shape *shape[] ={
        new Rectangle(10, 20),
        new Triangle(10, 20)
    };

    for (int i = 0; i < 2; i++) {
        std::cout << "Area = " << shape[i]->area() << std::endl;
    }

    return 0;
}
