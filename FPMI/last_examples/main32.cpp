#include<iostream>

// Vocabulary types and type erasure idiom

//pair, tuple, variant, any, optional

//14.1 Union

struct S
{
    int i;
    double d;
    std::string str;
};


template <typename T>
union U {
    int i;
    double d;
    T str;

    U() : i(0) {}
    ~U() {}
};  


int main() {
    //std::cout << sizeof(S) << "\t" << sizeof(U) << "\n";

    U<std::string> u;

    //Active union member

    new (&u.str) std::string("abc");
    std::cout << u.str.size() << '\n';

    u.str[2] = 'd';
    std::cout << u.str << '\n';

    u.str.~basic_string<char>();
    u.d = 5.0;

    std::cout << u.d  << '\n';
}