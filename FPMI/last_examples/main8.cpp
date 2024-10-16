#include<iostream>

//Template instantiation.

template<int N>
struct Danger {
    int a[N];
};

//incomplete type
template<typename T,int N>
struct S {
    //Danger<N> d;

    void f() {
        Danger<N> d;
    }

    void g() {
        Danger<-1> d;
    }

    
};

//explicit instantiation
//template struct S<int,-1>;

int main(){
    int x;
    S<int,-1> s;
    //S<int,-1>& ps = reinterpret_cast<S<int,-1>&>(x);
    //ps.g();
    //S<int,-1> s;
    //Danger<-1> d;
}

