#include<iostream>
#include<functional>
// std::function. c++11

// std::bind and its usage

// std::invoke, std::invoke_result

bool greater(int x, int y)
{
   return x>y;  
}

struct Equal {
    bool operator()(int x, int y) const {
        return x==y;
    }
};

struct S
{
    bool not_equal(int x,int y)  {
        return x!=y;
    }
};

template<typename T>
void f(const T&) = delete;

void test_bind(){

    std::function<bool(int,int)> compare =[](int x,int y) { return x<y; };    

    auto compare_with_zero = std::bind(compare,std::placeholders::_1,0);


    std::cout << compare(3,2) << '\n';
    std::cout << compare_with_zero(3) << '\n';
    //f(compare_with_zero);
    
    auto revere_compare = std::bind(compare, std::placeholders::_2,std::placeholders::_1);
    std::cout << revere_compare(1,2);
    // std::cout << f(1,2) << '\n';

    // f = greater;

    // std::cout << f(1,2) << '\n';

    // f = Equal();

    // std::cout << f(1,2) << '\n';

    // std::function<bool(const S&, int ,int)> ff = &S::not_equal;

    
}

int main(){
    std::function<bool(int,int)> compare =[](int x,int y) { return x<y; };    

    std::cout << std::invoke(compare, 1,2)<< '\n';

    std::cout << std::invoke(Equal(),1,2) << '\n';

    auto not_equal = &S::not_equal;

    S s;
    (s.*not_equal)(1 , 2);

    std::cout << std::invoke(not_equal, s,1,2) << '\n';
}