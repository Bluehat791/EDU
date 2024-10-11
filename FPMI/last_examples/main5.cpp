#include<iostream>
#include<array>
#include<vector>
//template template parameters

template <typename T,template<typename> class Container = std::vector>
struct Stack {
    Container<T> c;
};

int main() {
    Stack<int> s;
}