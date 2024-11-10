#include<iostream>
#include<vector>
//16. SFINAE idiom, template metaprogramming and compile-time computations

//16.1 Idea and basic example of SFINAE

//SFINAE = Substitutional Failure Is Not An Error!

//integral_constant, true_type and false_type 

// 16.5 is_constructible, is_assignable, etc

struct S
{
    size_t size() & {
        return 0;
    }
};


template<typename T>
auto f(const T& x) -> decltype(T().size()){
    std::cout << 1;
    return 1;
}

size_t f(...) {
    std::cout << 2;
    return 2;
}

//16.2 Check of method presence in a class.

//decltype: type -> its type
//declval: type -> value of its type

using std::declval;

template<typename T, T value_>
struct integral_constant {
    static const T value = value_;
};

struct true_type: public integral_constant<bool, true> {};
struct false_type: public integral_constant<bool, false> {};

template<typename T, typename... Args>
struct has_method_construct
{
private:

    template<typename TT, typename... AArgs,
             typename = decltype(declval<TT>().construct(AArgs()...))>
    static true_type f(int);

    template<typename...>
    static false_type f(...);

public:
    //static const bool value = sizeof(f<T,Args...>(0))==sizeof(int);
    using type = decltype(f<T,Args...>(0));
};

template<typename T, typename... Args>
bool has_method_construct_v =  std::is_same_v<has_method_construct<T,Args...>::type,true_type>;

struct Test
{
    void construct(int,int);
    void construct(double);
    void construct(const std::string&);
};


int main(){
    
    std::cout << has_method_construct_v<Test,int,int> << '\n';
    std::cout << has_method_construct_v<Test,int,int,int> << '\n';

    
}