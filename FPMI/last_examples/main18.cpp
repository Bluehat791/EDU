#include<iostream>

//Exceptions in destructors

struct S{
    S(){
        std::cout << "S\n";
    }

    ~S() noexcept(false) {
        std::cout << "~s\n";
        if(!std::uncaught_exception())
            throw 2;
    }
};

void f(){
    S s;

    throw 1;
}

void g(){
    S s;
}

int main(){
    try
    {
        g();
    }
    catch(...)
    {
        std::cerr << "caught in main\n" << '\n';
    }
    
}