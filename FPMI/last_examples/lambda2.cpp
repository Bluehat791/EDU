#include<iostream>

//lambda function as objects

template<typename T>
void g(const T&) = delete;

struct S
{
    S() { std::cout << "created!\n";}
    S(const S&) { std::cout << "copy!\n";}
    
    S& operator=(const S&) { std::cout << "copy-assign\n"; return *this;}
    S(S&&) { std::cout << "move!\n";}
    ~S() { std::cout << "destroy!\n";}
};


int main() {
    S s;
    auto f = [](int x,int y) {
        return x<y;
    };


    //auto ff = std::move(f);

    decltype(f) ff;

    //f = ff;
    //std::cout << typeid(f).name() << '\n';
    std::cout << sizeof(f) << '\n';
}