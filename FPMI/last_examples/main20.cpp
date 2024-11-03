#include<iostream>

// Function-try block.
// 

//weak exception-safe
//strong exception safety 


struct S
{
    int x = 0;
    std::string s;

    S(int x, const::std::string& s) noexcept try :x(x), s(s){

    } catch (...){

    }
};


void f(int y) noexcept try {
    
    int x = 0;

} catch (...) {
    y =1;
}

int main() {

}