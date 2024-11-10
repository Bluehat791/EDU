#include<iostream>

//14.3 std::launder function

struct S
{
    const int x;
};

union U {
    S s;
    float f;
    U(){}
};

int main(){
    S* s = new S{1};

    std::cout << s->x << '\n';

    new(s) S{2};
    std::cout << std::launder(s)->x << '\n'; //may be 1,UB
}
