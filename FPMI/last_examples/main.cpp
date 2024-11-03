#include<iostream>
#include<cstddef>
//Alignments

struct alignas(16) S
{
    int x;
    double e;
    int z;
};


int main(){
    
    std::cout << sizeof(S);

    //since c++11
    std::cout << alignof(S)<< '\n';

    std::cout << alignof(std::max_align_t) << '\n';
}