#include <iostream>

class Figure {
public:
    virtual int Perimeter() const = 0;  
    virtual ~Figure() = default;        
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {}

    int Perimeter() const override {
        return a_ + b_ + c_;
    }

private:
    int a_, b_, c_;
};

class Rectangle : public Figure {
public:
    Rectangle(int a, int b) : a_(a), b_(b) {}

    int Perimeter() const override {
        return 2 * (a_ + b_);
    }

private:
    int a_, b_;
};