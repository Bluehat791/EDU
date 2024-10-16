#include<iostream>
#include<type_traits>

//variadic templates

template<typename First, typename Second,typename... Tail>
struct is_homogeneous {
    static const bool value = std::is_same_v<First,Second> && is_homogeneous<Second,Tail...>::value;
};

template<typename T,typename U>
struct is_homogeneous<T,U> {
    static const bool value = std::is_same<T,U>;
};



void print() {}


template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail) {
    std::cout << head << ' ';
    print(tail...);
}

int main(){
    //print(1,2,3,"afesd",3,0);

    std::cout << is_homogeneous<int,int,int>::value << '\n';
    std::cout << is_homogeneous<int,char,double>::value << '\n';

}