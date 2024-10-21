#include <iostream>
#include <vector>
//exceptions.

//idea of exceptions? basic syntax.

//7.2 difference between exceptions and RE.

int inv(double x) {
    if(x==0){
        throw std::string("aaaaaa");
    }

    return 1/x;
}


int main(){

    
    try
    {

        std::vector<int> v;
     //   v.at(10000000)=13;
        
    }
    catch(...)
    {
        std::cout << "error";
    }
    
}