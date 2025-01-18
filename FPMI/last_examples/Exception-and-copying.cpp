#include <iostream>

//Exception and copying

struct S {
    S(){}
    S(const S&) {
        std::cout << "copy\n";
    }
    ~S(){
        std::cout <<"destruct\n";
    }
};

void f(){
    S s;
    throw s;
}

void g(){
    try
    {
        f();
    }
    catch(S& s)
    {
        std::cerr << "couth" << '\n';
        throw;
    }
    
}

int main(){
    try
    {
        g();
    }
    catch(S& s)
    {
        std::cerr << "couth in main" << '\n';
    }
    
}