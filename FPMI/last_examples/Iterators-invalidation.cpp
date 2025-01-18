#include <iostream>
#include <vector>
#include <deque>
#include <list>
//Containers/
// 

//Sequence containers: 
// vector: push_back, pop_back - amortized O(1)
    // [], at - guaranteed O(1)

// - deque : push_back,pop_back,push_front, pop_front -  O(1)
    // [], at -guaranteed O(1)

// ->[.....XXXX]
// ->[XXXXXXXXX]
// ->[XXX......]

// - list: push_back,pop_back,push_front,pop_front -guaranteed O(1)
    // insert, erase - guaranteed O(1)
// - forward_ist
//  push_front,pop_front - guaranteed O(1)
//  insert, eraser - guaranteed O(1)

//Associative containers;
// - map, set
//   [](map only), at - guaranteed O(log n)
//  insert,erase - guaranteed O(log n)

// -unordered_map, unordered_set since c++11
// (map only) [],at - expected O(1)
//  insert,erase - expected O(1)
//
//
//

//Iterators

//Iterators invalidation

struct S
{
    int x = 0;
    //S()=default;
    S(int x):x(x) {}
    S(const S&) = delete;
};


int main(){
    std::list<int> v(1);
    std::list<int>::iterator it = v.begin();

    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(i);
    }

    *it = 100;
    

    const std::list<int> a{1,2,3,4,5,6};
    //since c++11
    for (int x:a){
        std::cout << x;
    }
    
    // std::deque<S> v;
    // for (size_t i = 0; i < 100; i++)
    // {
    //     v.emplace_back(0);
    // }
    
    

}