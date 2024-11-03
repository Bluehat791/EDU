#include<iostream>

// reference qualifiers

struct Data {
    Data(const std::string& s): data(s) {}

    std::string getData() & {
        std::cout << "1\n";
        return data;
    }
    std::string getData() && {
        std::cout << "2\n";
        return data;
    }


private:
    std::string data;
};

void f(Data&& x){

    std::string data = x.getData();
}

int main(){
    Data d("abc");
    f(std::move(d));
}