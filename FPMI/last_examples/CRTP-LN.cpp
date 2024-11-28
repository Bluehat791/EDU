#include<iostream>

template<typename T>
class Counter {
public:
    Counter(){
        ++created;
        ++alive;
    }

    Counter(const Counter&) {
        ++created;
        ++alive;
    }

    ~Counter(){
        --alive;
    }

    static int howManyAlive() {
        return alive;
    }

    static int howManyCreated(){
        return created;
    }

private:
    static int created;
    static int alive;

};

template<typename T>
int Counter<T>::created(0);

template<typename T>
int Counter<T>::alive(0);

class MyClass : public Counter<MyClass> {
    // класс с каким-то функционалом
};

class AnotherClass : public Counter<AnotherClass> {
    // еще один класс с другим функционалом
};


template<typename Derived>
class Vehice {
public:
    int getNumberOfWheels() const {
        return static_cast<const Derived*>(this)->getNumberOfWheelsImpl();
    }
};

class Car : public Vehice<Car> {
public:
    int getNumberOfWheelsImpl() const {
        return 4;
    }
};

class Bicycle : public Vehice<Bicycle> {
public:
    int getNumberOfWheelsImpl() const {
        return 2;
    }
};


int main(){
    // MyClass a, b;
    // AnotherClass c;

    // std::cout << "MyClass alive: " << MyClass::howManyAlive() << '\n';
    // std::cout << "AnotherClass alive: " << AnotherClass::howManyAlive() << '\n';

    // {
    //     MyClass d;
    //     std::cout << "MyClass alive(in scope): " << MyClass::howManyAlive() << '\n';
    // }

    // std::cout << "MyClass alive(out of scope): " << MyClass::howManyAlive() << '\n';
    // std::cout << "MyClass created: " << MyClass::howManyCreated() << std::endl;
    // std::cout << "AnotherClass alive: " << AnotherClass::howManyAlive() << std::endl;
    // std::cout << "AnotherClass created: " << AnotherClass::howManyCreated() << std::endl;

    Car myCar;
    Bicycle myBicycle;

    std::cout << "Car has " << myCar.getNumberOfWheels() << " wheels.\n";
    std::cout << "Bicycle has " << myBicycle.getNumberOfWheels() << " wheels.\n";
}