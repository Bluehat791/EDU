#include <iostream>
#include <stdexcept>
#include <vector>

#include <string>

class Animal {
public:
    virtual std::string Voice() const {
        return "Not implemented yet";
    }
    virtual ~Animal() {
    }
};

class Tiger: public Animal {
    public:
    Tiger(){
        std::cout << "Construct Tiger\n";
    }
    std::string Voice() const override {
        return "Rrrr";
    }
    ~Tiger(){
        std::cout << "Destructor Tiger\n";
    }
};

class Wolf: public Animal {
    public:
    Wolf(){
        std::cout << "Construct Wolf\n";
    }
    std::string Voice() const override {
        return "Wooo";
    }
    ~Wolf(){
        std::cout << "Destructor Wolf\n";
    }
};

class Fox: public Animal {
    public:
    Fox(){
        std::cout << "Construct Fox\n";
    }
    std::string Voice() const override {
        return "Tyaf";
    }
    ~Fox(){
        std::cout << "Destructor Fox\n";
    }
};
#include<memory>
using Zoo = std::vector<std::shared_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            zoo.push_back(std::make_shared<Tiger>());
        } else if (word == "Wolf") {
            zoo.push_back(std::make_shared<Wolf>());
        } else if (word == "Fox") {
            zoo.push_back(std::make_shared<Fox>());
        } else
            break;
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal->Voice() << "\n";
    }
}

int main(){

    Zoo myzoo = CreateZoo();
    Process(myzoo);
}