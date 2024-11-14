#include <fstream>
#include <iostream>
#include <string>

template <typename A, typename B>
class D {
private:
    A* x;
    B* y;

public:
    D() {
        x = new A();
        y = new B();
    }

    D(const D& other) {
        x = new A(*other.x);
        y = new B(*other.y);
    }

    D& operator = (const D& other) {
        *x = *other.x;
        *y = *other.y;
        return *this;
    }

    ~D() {
        delete x;
        delete y;
    }
};

int main() {
   

}   