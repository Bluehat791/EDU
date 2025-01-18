#include<iostream>
#include<memory>
//Smart pointers.

// unique_ptr

//

template<typename T>
class unique_ptr
{
private:
    T* ptr;
public:
    explicit unique_ptr(T* ptr): ptr(ptr) {}

    ~unique_ptr(){
        delete ptr;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr(unique_ptr&& another) noexcept: ptr(another.ptr){
        another.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& another) noexcept {
        delete ptr;
        ptr = another.ptr;
        another.ptr = nullptr;
    }
    
    T& operator*() const {
        return *ptr;
    }

    T* operator->()const{
        return ptr;
    }

    
};



void f(int x){
    std::unique_ptr<int> p(5);
    auto pp = p;

    if(x==0)
        throw 1;

}

int main(){

}