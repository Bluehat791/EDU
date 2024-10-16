#include <iostream>

template<typename... Args>
struct tuple_t;

template<typename Head,typename...Tail>
struct tuple_t<Head,Tail...> : tuple_t<Tail...>
{
    tuple_t(Head h,Tail... tail)
        : tuple_t<Tail...>(tail...), head_(h)
    {}

    typedef tuple_t<Tail...> base_type;
    typedef Head           value_type;

    base_type& base = static_cast<base_type&>(*this);
    Head head_;
};

template<>
struct tuple_t<>
{};

template<int I, typename Head,typename... Args>
struct getter{
    typedef typename getter<I-1,Args...>::return_type return_type;
    static return_type get(tuple_t<Head,Args...> t){
        return getter<I-1,Args...>::get(t);
    }
};

template<typename Head, typename... Args>
struct getter<0, Head, Args...>
{
            typedef typename tuple_t<Head, Args...>::value_type return_type;
            static return_type get(tuple_t<Head, Args...> t)
            {
                return t.head_;
            }
};

template<int I,typename Head,typename... Args>
typename getter<I,Head,Args...>::return_type
get(tuple_t<Head, Args...> t){
    return getter<I, Head, Args...>::get(t);
}


int main() {
    tuple_t<int, double, int> t(12, 2.34, 89);
    std::cout << t.head_ << " " << t.base.head_ << " " << t.base.base.head_ << std::endl;
    std::cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << std::endl;
}