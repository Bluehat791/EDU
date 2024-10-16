#include<iostream>

//Dependent name.

template<typename T>
struct Base{
    int x;
};

template<typename T>
struct Derived : Base<T>{
    void f() {
        this->x = 1;
    }
};



template<typename T>
struct S {
    using x = T;
};


template<>
struct S<int> {
    static int x;
};

//int a;

template<int N>
struct A {
};

template<typename T>
struct SS {
    template <int N>
    struct A {};
};

template<>
struct SS<int> {
    static const int A = 5;
};

template<typename T>
void f(){
    typename S<T>::x  a; 
}

template<typename T>
void g() {
     typename SS<T>::template A<10> a;
}

int main(){
      //f<int>();                                                                                                                                                          
}