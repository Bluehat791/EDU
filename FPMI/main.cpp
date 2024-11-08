#include<iostream>
#include<unordered_map>
#include<vector>
#include<deque>
//type deduction (since c++11)

// auto keyword.

template<typename T, typename U>
auto& f(const T& x, const U& y) {
    return x<y?x:y;
}

void g(const auto& x) {

}

// 12.2 decltype. (declared type)

struct S
{
    int x = 1;
    std::string s = "abc";
};


//since c++14
template<typename Container>
decltype(auto) get_at(Container& container,size_t index){
    // some additional work
    return (container[index]);
}

template<typename T>
class C {
    C() = delete;
};


//decltype: expression -> its type
//declval: type -> expression of this type

template<typename T>
class BigClass {

};

//incomplete type
struct SS;


template<typename T>
std::add_rvalue_reference_t<T> declval() noexcept;

//12.4 std::common_type implementation.

template<typename Head, typename... Tail>
struct common_type
{
    using type = typename common_type<Head, typename common_type<Tail...>::type>::type;
};

template<typename T, typename U>
struct common_type<T,U>
{
    using type = std::remove_reference_t<decltype(true? std::declval<T>() : std::declval<U>())>;
};

template<typename... Types>
using common_type_t = typename common_type<Types...>::type;

struct Granny
{
    /* data */
};

struct Mother: public Granny
{
    /* data */
};

struct Father: public Granny
{
    /* data */
};



int main() {


    C<common_type_t<Mother,Granny ,Father>>();

    int x =0;

    //SC<decltype((x))>();

    //decltype(throw 1)* y = &x;

    //decltype(expr)
    //if expr is lvalue of type T, then decltype return T&
    //if expr is prvalue of type T, then decltype return T
    //if expr is xvalue of type T, then decltype return T&&


    //12.3 structured bindings and tuples
    //since c++17
    
    //std::tuple<int,int,double> t{1,3,0.5};


    //S s;
    //auto& [x, y, z] = t;
    
    

    //std::cout << x << " " << y <<  ' ' << z <<  '\n';
    //std::get<int>(t) = 1;
    //std::cout << x << " " << y << '\n';

    //std::cout << x << y << '\n';
    
}