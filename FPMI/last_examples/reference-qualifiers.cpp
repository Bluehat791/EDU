#include<iostream>
#include<vector>
// reference qualifiers

template<typename T>
std::remove_reference_t<T>&& move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}

//move_if_noexcept
template<typename T>
T f() noexcept;

template<typename T>
std::conditional_t<noexcept(T(f<T>())),T&&, const T&> move_if_noexcept(T& x) noexcept {
    return std::move(x);
}

struct S
{
    S() noexcept{
        std::cout << "Created!";
    }
    S(const S&){
        std::cout << "Copy!";
    }
    S(S&&) noexcept {
        std::cout << "Move!";
    }
    ~S(){
        std::cout << "Destroy!";
    }

};


int main(){
    S s;
    S&& r = move_if_noexcept(s);
    return 0;   
}