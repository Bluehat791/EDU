#include<iostream>

//

//perfect forwarding problem

template<typename T>
T&& forward(std::remove_reference_t<T>& x){
    return static_cast<T&&>(x);
}

template<typename T>
T&& forward(std::remove_reference_t<T>&& x){
    static_assert(!std::is_lvalue_reference_v<T>);
    return static_cast<T&&>(x);

}


//case of lvalue
//T == type&
//type(x) = type&
//T&& == type&

//case of rvalue
//T == type
//typeof(x) ==type&
//T&& == type&&


void f(int&) {
    std::cout << 1 << '\n';
}

void f(int&&) {
    std::cout << 2 << '\n';
}

template<typename T>
std::remove_reference_t<T>&& move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}

struct Base
{
    virtual ~Base(){}
};

struct Derived : public Base {
};

int main(){

    Base d = Derived();
 
}