#include<iostream>
#include<type_traits>

//variadic templates since c++1

///5.9 Fold expression (since c++17)

template<typename Head, typename... Tail>
struct is_homogeneous {
    static const bool value = (std::is_same_v<Head,Tail> && ... );
};

// template<typename T,typename U>
// struct is_homogeneous<T,U> {
//     static const bool value = std::is_same_v<T,U>;
// };



void print() {}


template <typename... Args>
void print(const Args&... args) {
    (std::cout << ... << args) << '\n';

    //(... op args); -> (args1 op args2)
    //op arg1 op arg2 op arg3
    //(args op ...)
    //(x op ... op args)
    //(args op ... op x)
}

int main(){
    print(1,2,"afesd",3.0);

    std::cout << is_homogeneous<int,int,int>::value << '\n';
    std::cout << is_homogeneous<int,char,double>::value << '\n';

}