#include<iostream>

//virtual inheritance

struct Granny {
    int g = 0;
};

struct Mom : public virtual Granny
{
    int m =1;
};

struct Dad : public virtual Granny
{
    int d =2;
};

struct Son : public Mom, public Dad
{
    int s = 3;
};

// [Mom::g][Mom::m][Dad::d][Sons::s]
// [mom_ptr][Mom:m][dad_ptr][Dad::d][Sons::s][Granny::g]
int main(){
    Son s;
    Dad* pd = &s;
    pd->g;

    std::cout << &s << "\n";
    std::cout << &s.Dad::d << " " << &s.Mom::m << '\n';
    std::cout << &s.Dad::g << " " << &s.Mom::g << '\n';

    Granny& g = s;
    std::cout << sizeof(s) << '\n';
    return 0;
}