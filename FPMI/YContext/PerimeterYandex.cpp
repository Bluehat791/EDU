#include<iostream>
#include <memory>
#include <vector>

class Figure
{
public:

    virtual int Perimeter() const = 0;

    virtual ~Figure()
    {};
};

class Triangle : public Figure 
{
    int a,b,c;
public:
    Triangle(int a_, int b_, int c_)
        : a(a_), b(b_), c(c_)
        {}

    int Perimeter() const override
    {
        return a+b+c;
    }
};

class Rectangle : public Figure
{
    int a,b;
public:
    Rectangle(int a_, int b_)
        : a(a_), b(b_)
        {}
    
    int Perimeter() const override
    {
        return (a+b)*2;
    }
};

int main() {
    std::vector<Figure*> figures;

    std::string type;

    while (std::cin >> type && type!="out") {
        if (type == "Triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            figures.push_back(new Triangle(a, b, c));
        } else if (type == "Rectangle") {
            int a, b;
            std::cin >> a >> b;
            figures.push_back(new Rectangle(a, b));
        }
    }

    for (Figure* f : figures) {
        std::cout << f->Perimeter() << "\n";
    }

    for (Figure* f : figures) {
        delete f;
    }
}