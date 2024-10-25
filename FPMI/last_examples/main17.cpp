#include<iostream>
#include<memory>

struct A{
  A(){
    std::cout << "A\n";
  }  
  ~A(){
    std::cout << "~A\n";
  }
};

struct S{
    A a;
    int* p;
    int* pp;
    S(){
        p = new int(5);
        throw 1;
        p = new int(10);
    }
    ~S(){
        std::cout << "~S\n";
        delete pp;
        delete p;
    }
};

void f(){

    //RAII = resource acqusition is initialization
    std::shared_ptr<int> p( new int(5));
    

    throw 1;
}

int main(){
    try
    {
        f();
    }
    catch(...)
    {
        std::cerr << "caught\n" << '\n';
    }
    

    return 0;
}