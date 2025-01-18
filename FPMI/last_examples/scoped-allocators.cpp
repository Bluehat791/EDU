#include<iostream>
#include<vector>
#include<string>
#include<scoped_allocator>

template<typename T>
class MyAllocator : public std::allocator<T> {
public:
MyAllocator(){}

    template<typename U>
    MyAllocator(const MyAllocator<U>&){}

    T* allocate(size_t count) const {
        std::cout << "Allocate\n";
        return ::operator new(count *sizeof(T));
    } 

    void deallocate(T* ptr, size_t count) {
        ::operator delete(ptr);
    }

    template<typename ...Args>
    void construct(T* ptr, const Args&... args){
        new(ptr) T(args...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }
};

template<typename OuterAlloc, typename... InnerAlloc>
struct scoped_allocator_adapter 
{   
    template< typename T, typename... Args>
    void construct(T* ptr, const Args&.. args) {
        if()
    }
};


//scoped allocators.


int main() {
    using MyVector = std::vector<int, MyAllocator<int>>;
    
    MyAllocator<MyVector> outer_alloc;
    MyAllocator<int> inner_alloc(outer_alloc);
    //using MyString = std::basic_string<char,std::char_traits<char>, MyAllocator<char>>;
    //std::vector<MyVector, MyAllocator<MyVector>> v(outer_alloc);
    std::vector<MyVector, std::scoped_allocator_adaptor<
    MyAllocator<MyVector>, >> v(outer_alloc);



    v.push_back(MyVector(5));
}