#include<iostream>
#include<vector>
#include<algorithm>
// capture this

//Default-capture and capture with initialization

struct S
{
    int a = 5;


    auto get_function(int i) {
        std::string s = "abcdef";
        //since c++14
        auto f = [i,s = std::move(s)]() {
            std::cout <<  s[i]  << '\n';
            
        };
        return f;
    }
};

int main() {

    int i =1;

    std::string ss = "xxx"; 
    {
        std::string s = "avbcd";
        
        auto g = [&, i](){std::cout <<  s[i] << '\n'; s[i]++;};

        g();
        g();
        //auto h = [&s](int i) {return s[i];};
    }

    return 0;

    std::vector<std::string> v{"abc","abcdef"};
    std::sort(v.begin(),v.end(),[](const auto& x, const auto& y) {return x[0]<y[0];});
    auto f = S().get_function(1);

    auto ff = S().get_function(2);

    std::cout << sizeof(f);

    f(); //UB!!!
    ff();

}
