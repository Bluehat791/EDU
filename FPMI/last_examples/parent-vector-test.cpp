#include <iostream> 
#include <vector>

template<typename T,typename U>
void f(T x, U y){
    std::cout << 1;
}

template<typename T>
void f(T x, T y){
    std::cout << 2;
}


void f(int x, int y){
    std::cout << 3;
}

template<typename T>
void g(T& x) {
    std::cout << 1 << '\n';
}

template<typename T>
void g(const T& x) {
    std::cout << 2 << '\n';
}

template<typename T, typename U = std::string>
void h(T x) {
    U y = 1;
    std::cout << y << '\n';
}

template<typename T>
struct S
{   
    S() = default;

    template<typename U>
    S(U& x) {
        std::cout << "construct" << '\n';
    }

    S(const S<T>&) {
        std::cout << "copy" << '\n';
    }
};

template<typename T>
void ff(const std::vector<T>& v) {
    std::cout << 1 << "\n";
}

int main() {
    // f<>(0.0,1);

    // f(1, 1.0);
    // f(1.0, 1.0);
    // f<>(1, 1);


    // const int x = 0;
    // g(x);

    //  h(0);
    std::vector<int> v = {1,2,3};
    ff<int>({1,2,3});

    S<int> s;
    S<int> ss =s;

    return 0;
}