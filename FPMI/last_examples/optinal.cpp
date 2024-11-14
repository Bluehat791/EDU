#include<iostream>

template<typename T>
class optional {
    char val[sizeof(T)];
    bool initialized = false;
public:
    optional(const T& newval) : initialized(true) {
        new (val) T(newval);
    }

    optional(){}
    ~optional() {
        if(initialized) {
            reinterpret_cast<T*>(val)->~T();
        }
    }
    bool has_value() const {
        return initialized;
    }
    operator bool() const {
        return initialized;
    }
    const T& operator*() const & {
        return reinterpret_cast<T&>(*val);
    }
    T& operator*() && {
        return reinterpret_cast<T&>(*val);
    }
    T& operator*() const && {
        return reinterpret_cast<T&>(*val);
    }
    T& operator*() & {
        return reinterpret_cast<T&>(*val);
    }

    //since c++23
    decltype(auto) value(this auto& self) {
        if(!initialized)
            throw std::bad_optional_access();
        using DesiredType = decltype(std::forward_like<decltype<self>>(std::declval<T>()));
        return reinterpret_cast<DesiredType>(*self.value);
    }

    const T& value_or(const T& other) const {
        return initialized ? reinterpret_cast<T&>(*val) : other;
    }
};
