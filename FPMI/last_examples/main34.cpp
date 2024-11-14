#include<iostream>
#include<vector>
// Class Template Argument Deduction (CTAD)

template<typename T>
class Debug {
    Debug() = delete;
};

template<typename T>
struct Vector{
    template<typename Iter>
    Vector(Iter, Iter) {}
};

//Explicit template deduction guides
template<typename Iter>
Vector(Iter,Iter) -> Vector<typename std::iterator_traits<Iter>::value_type>;

struct A
{};
struct B
{};


template<typename... Args>
struct S : Args... {};

// template<typename T, typename U>
// S(T,U) -> S<T,U>;




int main() {

    S s{A(), B()};

    std::vector v = {1,2,3,4,5};

    Vector v2(v.begin(),v.end());

    //Debug<decltype(v2)>();
}