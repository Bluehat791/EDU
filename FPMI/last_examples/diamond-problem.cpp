#include<iostream>

//diamond problem and ambigiuous casts

struct Granny {
private:
    friend int main();
    int g = 0;
};

struct Mom : public Granny
{
    int m =1;
};

struct Dad : public Granny
{
    int d =2;
};

struct Son : public Mom, public Dad
{
    int s = 3;
};

// [Mom::g][Mom::m][Dad::g][Dad::d][Sons::s]

int main(){
    Son s;
    Dad* pd = &s; // other address
    
    Mom* pm = reinterpret_cast<Mom*>(pd);

    Mom m;
    Granny& g = m;

    g.g;
    m.g;

    //Son* ss = static_cast<Son*>(pd);

    //Dad& d = reinterpret_cast<Dad&>(s);
    //std::cout << &s << ' ' << d << '\n';
    return 0;
}