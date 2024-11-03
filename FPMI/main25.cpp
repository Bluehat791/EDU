#include <iostream>
#include<vector>

// Move-semantics and rvalue-refences

// Introduction, problems cases

// std::move function

// Rvalue-references, move-operations

class String {
    char * arr;
    size_t sz;
    size_t cap;

public:

    String(const String& s) = default;

    String(String&& s) : arr(s.arr),sz(s.sz), cap(s.cap){
        s.arr = nullptr;
        s.sz = 0;
        s.cap = 0;
    }

    // String& operator=(String&& s){
    //     String news(std::move(s));
    //     swap(news);
    //     return *this;
    // }

};

struct S
{
    std::vector<int> v;
    std::string s;
};


template<typename T>
void  swap(T& x, T& y) {
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

std::string f() {
    // ....
    return std::string("abcdef");
}

int main(){

    S x;
    S y = std::move(x);

    std::string s = "abc";
    std::string ss = std::move(s);
    std::vector<std::string> v;
    
    
    //v.push_back(std::string("abdfcxs"));

    v.push_back(std::move(ss)); //since c++11 this is already correct

    std::cout << ss.size();
    return 0;
}