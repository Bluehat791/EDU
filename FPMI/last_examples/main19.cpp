#include<iostream>
#include<exception>
//Exception specifications and noexcept keyword

//std::runtime_error
//std::logic_error
//
//std::out_of_range
//std::bad_alloc
//std::bad_cast

void g()  {
    throw std::runtime_error("hi!");
}

void f() noexcept(noexcept(g)) {
    g();
}

int main(){
    int * p = new int;
    std::cout << noexcept(delete p);

    // try
    // {
    //     f();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    
    std::runtime_error re("Hello\n");

    std::cout << re.what();

   return 0;
}

