#include<iostream>>

//multiple inheritance

struct Mom
{
    void f() {std::cout << "Mom::f" << '\n';}
    int m =1;
};

struct Dad
{
    void f() {std::cout << "Dad::f" << '\n';}
    int d =2;
};

struct Son : public Mom, public Dad
{
    int s = 3;
};

// [ Mom::m][Dad::d][Sons::s]

int main(){
    Son s;
    s.Mom::f();
    std::cout << sizeof(s) << '\n';
    std::cout << &s.m << ' ' << &s.d << ' ' << &s.s << '\n';

    return 0;
}