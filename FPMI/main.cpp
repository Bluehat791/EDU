#include<iostream>
#include<vector>
#include<type_traits>

//std::enable_if and its usage.

template<bool B,typename T = void>
struct enable_if
{
    
};

template<typename T>
struct enable_if<true,T>
{
    using type = void;
};

template<bool B,typename T = void>
using enable_if_t = typename enable_if<B,T>::type;



template<typename T, typename = std::enable_if_t<std::is_class_v<T>>>
void f(const T& x) {
    std::cout << 1;
}

void f(...) {
    std::cout << 2;
}

int main(){

    std::string s("abc");

    f(s);

    f(1);

}