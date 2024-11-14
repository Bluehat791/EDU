#include<iostream>
#include<tuple>

//Tuple and structure bindings


int main(){
    std::tuple t{1,2.0,'a'};
    
    auto d = std::get<1>(std::move(t));
    d = 3.14;
    std::cout << std::get<1>(t) << '\n';

    //structure bindings
    auto&&[x,y,z] = std::move(t);
    for(const auto& [key,value]: map){}

    z = 'b';
    std::cout << std::get<2>(t)<< '\n';
}