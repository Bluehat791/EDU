#include<iostream>
#include<variant>
//14.2 std::variant and its implementation

template <size_t N, typename T, typename... Types>
struct get_index_by_type {
    static const size_t value = N; 
};

template <size_t N, typename T, typename Head, typename... Tail>
struct get_index_by_type<N,T,Head,Tail...> {
    static const size_t value = std::is_same_v<T,Head> ? N : get_index_by_type<N+1, T, Tail...>::value; 
};


template<typename... Types>
class variant;

template<typename T, typename... Types>
struct VariantAlternative {

    //crtp
    using Derived = variant<Types...>;

    VariantAlternative(const T& value) {
       static_cast<Derived*>(this)->storage.put<sizeof...(Types)>(value); 
    }

    VariantAlternative(T&& value) {
       static_cast<Derived*>(this)->storage.put<sizeof...(Types)>(std::move(value)); 
    }

    void destroy() {
        auto this_ptr = static_cast<Derived*>(this);
        if(get_index_by_type<0,T, Types...>::value == this_ptr->current) {
            //this_ptr->storage.
        }
    }

};


template<typename... Types>
class variant : private VariantAlternative<Types,Types...>... {
private:

    template<typename... TTypes>
    union VariadicUnion {};

    template <typename Head,typename... Tail>
    union VariadicUnion<Head,Tail...> {
        Head head;
        VariadicUnion<Tail...> tail;  

        template<size_t N, typename T>
        void put(const T& value) {
            if constexpr (N==0){
                new(&head) T(value);
            } else {
                tail.put<N-1>(value);
            }
        }

    };

    VariadicUnion<Types...> storage;
    size_t current = 0;

    

public:

    using VariantAlternative<Types,Types...>::VariantAlternative...;
    
    ~variant(){
        (VariantAlternative<Types,Types...>::destroy(),...);
    }

    // template<typename T>
    // variant(const T& value){
    //     // static assert( T is one of Types...)
    //     current = get_index_by_type<0,T,Types...>::value;
    //     storage.put<get_index_by_type<0,T, Types...>::value>(value);
    // }

    size_t index() const {
        return current;
    }

    template <typename T>
    bool hold_alterantive() const {
        return get_index_by_type<0,T,Types...>::value == current;
    }

};


int main(){

    std::variant<int, double, std::string> v =1;
    

    v = "std";

    std::cout << std::get<std::string>(v) << '\n';

    v = 5.0;

    std::cout << std::holds_alternative<int>(v) << '\n';

    std::cout << v.index() << '\n'; 
}