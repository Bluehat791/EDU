#include<iostream>
#include<vector>
//Containers
//Vector implementation.

template<typename T, typename Alloc = std::allocator<T>>
class Vector {
private:
    T* arr;
    size_t sz;
    size_t cap;

    Alloc alloc;
    //size_t size() const
    //size_t capacity() const
public:

    Vector(size_t count , const Alloc& alloc = Alloc()) : alloc(alloc){
        reserve(count);
        for (size_t i = 0; i < count; i++)
        {
            alloc.construct(arr+i,value);
        }
        

    }

     void reserve(size_t n){
        if(n<=cap) return;

        T* newarr = AllocR.allocate(n);
        //T* newarr = new T[n];
        size_t i =0;

        try
        {
            std::uninitialized_move(arr,arr+sz,newarr);
        }
        catch(...)
        {   
            alloc.deallocate(newarr,n);
            //delete[] reinterpret_cast<int8_t*>(newarr);
            throw;
        }
        

        // try {
        // for(;i<sz;++i)
        // {
        //     new(newarr + i) T(arr[i]); // placement new
        //     //newarr[i] = arr[i];
        // }} catch(...){
        //     for (size_t j = 0; j<i; ++j)
        //     {
        //         (newarr+i)->~T();
        //     }
        //     delete[] reinterpret_cast<int8_t*>(newarr);
        //     throw;
        // }
        for (size_t i = 0; i < sz; i++)
        {
            alloc.destroy(arr+i);
        }
        

        alloc.deallocate(arr, sz);
        //delete[] reinterpret_cast<int8_t*>(arr);
        arr = newarr;
        cap = n;
    }

    void resize(size_t n,const T& value = T()){
        if(n>cap) reserve(n);
        for (size_t i = sz; i < n; i++)
        {
            new(arr+i) T(value);
        }
        if(n<sz){
            sz=n;
        }
        
    }


    //
    template<typename... Args>
    void emplace_back(Args&&.. args){
        if(cap==sz){
            reserve(2*sz);
        }
        std::allocator_traits<T>::construct(alloc ,arr+sz, std::forward<Args>(args)...);
        ++sz;
    }

    void push_back(const T& value){
        if(cap==sz){
            reserve(2*sz);
        }
        new(arr+sz) T(value);
        ++sz;
    }

    void push_back(T&& value){
        if(cap==sz){
            reserve(2*sz);
        }
        new(arr+sz) T(std::move(value));
        ++sz;
    }

    void pop_back(){
        
        --sz;
        alloc.destroy(sz);
    }

    T& operator[](size_t i){
        return arr[i];
    }

    const T& operator[](size_t i) const {
        return arr[i];
    }

    T& at(size_t i){
        if(i<=sz)
            throw std::out_of_range("...");
        return arr[i];
    }
};

// vector<bool>

template<>
class Vector<bool> {
    uint8_t* arr;

private:
struct BitReference {
    uint8_t* bucket_ptr;
    uint8_t pos;

    BitReference operator=(bool b) {
        if (b)
            *bucket_ptr |=((uint8_t)1<<pos);
        else
            *bucket_ptr &= ~((uint8_t)1<<pos);
        return *this;
    }
    
    
    operator bool() const {
        return *bucket_ptr & (1<<pos);
    }
};
public:
    BitReference operator[](size_t i){
        uint8_t pos i % 8;
        uint8_t* ptr = arr +i/8;
        return BitReference(ptr,pos);
    }

};


template<typename T>
class C {
    template<typename U>
    C(const U&) = delete;
};

int main(){
    std::vector<bool> vb(10);

    C c(vb[5]);
    vb[5] = true;

    
    // std::vector<int> v;
    
    // for (size_t i = 0; i < 10; i++)
    // {
    //     v.push_back(i);
    //     std::cout << v.size() << "\t" << v.capacity() << '\n';
    // }
    

    // v.size();
    // v.capacity();
    return 0;
}