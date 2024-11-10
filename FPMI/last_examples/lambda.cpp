#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
//15. Lambda function and elemets of  functional programming. since c++11

//General idea, basic syntax

// Capture lists in lambda functions

struct MyCompare
{
    bool operator()(int x, int y) const{
        return std::abs(x-5)<std::abs(y-5);
    }
};


auto get_compare() {
    return [](int x, int y){ return x*x < y*y; };
}


void test1(){
    std::vector<int> v{4,6,24,4,5,2,5,25,623,1};

    auto f = [](int x, int y) -> bool {
            return std::abs(x-5)<std::abs(y-5);
    };

    std::map<int,int,decltype(f)> m;

    std::cout << get_compare()(1,2) << '\n';

    std::sort(v.begin(),v.end(), get_compare());

    [](int x){
        std::cout << x << '\n';
    }(5);

    for (const auto& x : v)
    {
        std::cout << x << ' '; 
    }
    

    
}

namespace N{
int a = 5; 
}

int main(){

    int a = 1;
    
    int b = 2;

    [&a, b](int x) {
        std::cout << x + a << '\n';
        ++a;
    }(5);

    std::cout << a << '\n';
}