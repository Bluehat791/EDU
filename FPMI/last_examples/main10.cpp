#include<iostream>
#include<type_traits>
#include<functional>
#include<vector>

// Template deduction rules & guides.


template<typename T>
class C{
    C() = delete;
};



template <typename T>
void f(T x) {
   x.get()=5;
    //C<T>();
//  std::cout << std::is_reference_v<T>;
}


template<typename T>
struct S {
    S(T& x){
        C<T>();
    }
};

//since c++17
//using define deduction rules
S(const char*) -> S<std::string>;

template<typename T>
S(const T&) -> S<T&>;

int main(){

    const int& x =5;
    S s(x);
    std::vector v(1,5);


    int x=0;
    
    //f(x);
    int& y = x;


    //since c++11
    f(std::ref(x));
    std::cout << x;

    //   std::reference_wrapper<int> r;
    //std::vector<std::reference_wrapper<int>> v;
}