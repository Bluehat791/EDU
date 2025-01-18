#include<iostream>
#include<type_traits> //since c++11
//basic type traits


template<typename T,typename U>
const bool is_same_v = is_same<T,U>::value

template<typename T>
struct remove_const {
    using type = T;
};

template<typename T>
struct remove_const_t<const T> {
    using type = T;
};

template<typename T>
using remove_const_t = remove_const<T>::type;

//
template<typename T>
struct remove_reference {
    using type = T;
};

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
using remove_reference_t = remove_reference<T>::type;
//
template<typename T>
struct remove_extent {
    using type = T;
};

template<typename T>
struct remove_extent<T[]> {
    using type = T;
};

template<typename T>
using remove_extent_t = remove_extend<T>::type;
//////////


/// 
/// 
///  
template<typename T, typename U>
struct is_same 
{
    static const bool value = false;
};

template<typename T>
struct is_same<T,T> 
{
    static const bool value = false;
};

template<typename T>
void g(T x) {

    std::decay_t<T>
    std::remove_const<T>::type y = x;
}

template<typename T,typename U>
void f(T x, U y) {

    std::cout << (std::is_same_v::value ? 1 : 2);


}

int main(){

}