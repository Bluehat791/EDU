#include<iostream>
#include<cstdlib>
#include<vector>
//New/delete overloading, allocators.

// Standard new-delete overloading

// void* operator new(size_t n){
//     std::cout <<"Allocated " << n << " bytes\n";
//     return malloc(n);
// }

// void operator delete(void* ptr, size_t n){
//     std::cout << "Deallocate " << n << " bytes\n";
//     free(ptr);
// }

// void* operator new[](size_t n){
//     std::cout <<"Allocated array " << n << " bytes\n";
//     return malloc(n);
// }

// void operator delete[](void* ptr){
//     std::cout << "Deallocate array " << " bytes\n";
//     free(ptr);
// }


struct S
{
    int x = 0;
    double d = 3.14;

    void* operator new(size_t n){
        std::cout <<"Allocated " << n << " bytes\n";
        return malloc(n);
    }

    void operator delete(void* p){
        std::cout <<"deallocated " << " bytes\n";
        free(p);
    }
};


void* operator new(size_t, void* ptr){
    return ptr;
}

void* operator new(size_t n, std::nothrow_t){
    return malloc(n);
}

struct mynew_t {};
mynew_t my_tag;

void* operator new(size_t n, mynew_t){
    return malloc(n);
}

void operator delete(void* ptr, mynew_t){
     std::cout << "I am here\n";
     free(ptr);
}

int main() {

    try
    {
        S* ptr = new(my_tag) S();
    }
    catch(...)
    {
        std::cerr << "Caugth" << '\n';
    }
    
    
    // ptr->~S();
    // operator delete(ptr, my_tag);

    // int* ptr = new(std::nothrow) int(5);

    // std::vector<int> v(5);
    // for (size_t i = 0; i < 10; i++)
    // {
    //     v.push_back(i);
    // }
    
    S* p = new S();
    delete p;

}
