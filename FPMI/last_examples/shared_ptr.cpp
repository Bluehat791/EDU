#include<iostream>
#include<memory>

//shared_ptr basic implementation

//13.3 make_shared, make_unique


// weak_ptr

// 13.5 allocate_shared

// 13.6 enable_shared_from_this 

// Curiously Recursive Template Pattern

//Application of type erasure in shared ptr

template<typename T>
class shared_ptr {
private:
    T* ptr = nullptr;
    size_t* counter = nullptr;

    DeleterBase* deleter = nullptr;

    struct DeleterBase {
        virtual operator()(T*);
        virtual ~DeleterBase(){}
    };

    template<typename U>
    struct DeleterDerived : public DeleterBase
    {   
        U deleter;
        DeleterDerived(const U& deleter) : deleter(deleter){}
        void operator()(T* ptr) override {
            deleter(ptr);   
        }
    };
    

    template<typename U>
    struct ControlBlock {
        size_t shared_counter;
        size_t weak_counter;
        U object;
    };

    template<typename U>
    class weak_ptr<U>;

    ControlBlock<T>* cptr = nullptr;

    template<typename U,typename... Args>
    friend shared_ptr<U> make_shared(Args&&... args);

    struct make_shared_t;

    template<typename... Args>
    shared_ptr(make_shared_t,ControlBlock<T>* storage_ptr){
        cptr(storage_ptr);
    }
public:
    shared_ptr() {}
    shared_ptr(T* ptr): ptr(ptr) , counter(new size_t(1))
    {
        if constexpr (std::is_base_of_v<enable_shared_from_this<T>, T>) {
            ptr -> wptr = /*....*/ ;         
        }
    }

    shared_ptr(const shared_ptr& other):
        ptr(other.ptr), counter(other.counter) {
            ++*counter;
        }
    
    shared_ptr(shared_ptr&& other):
        ptr(other.ptr),counter(other.ptr){
            other.ptr = nullptr;
            other.counter = nullptr;
        }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    size_t use_count() const {
        return *counter;
    }


    ~shared_ptr(){
        *counter;
        if(*counter > 0) return;
        delete counter;

        deleter(ptr);
    }

    // ~shared_ptr(){
    //     --cptr_shared_counter;
    //     if(cptr->shared_counter > 0){
    //         --cptr->counter;
    //         return;
    //     }

    //     if(cptr->weak_counter ==0){
    //         delete cptr;
    //         return;
    //     }

    //     cptr->object.~T();

    // }

};

template<typename T>
class enable_shared_from_this {
private:
    weak_ptr<T> wptr;

    template<typename U>
    friend class shared_ptr;
public:

    shared_ptr<T> shared_from_this() {
        return wptr.lock();
    }
};

struct S : public enable_shared_from_this<S>
{
    int x = 0;
    std::string str;
    S(int x,const std::string& str): x(x),str(str) {}
    shared_ptr<S> get_ptr() const {
        return shared_from_this();
    }
};



//since c++11
template<typename T,typename Alloc, typename... Args>
shared_ptr<T> allocate_shared(Alloc alloc, Args&&... args){

}

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args){
    return allocate_shared(std::allocator<T>(),std::forward<Args>(args)...)
    //auto ptr = new ControlBlock<T>{1,T{std::forward<Args>(args)...}};
    //return shared_ptr<T>(shared_ptr::make_shared_t(), ptr,
    //    std::forward<Args>(args...));
}

//since c++14
template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(std::forward<Args>(args)...);
}

int f(int x){
    // ...
    return result;
}

void g(const unique_ptr<int>& ptr, int x){
    //...
}




template<typename T>
class weak_ptr {
    ControlBlock<T>* cptr = nullptr;
public:
    weak_ptr(const shared_ptr<T>& ptr):
        cptr(ptr.cptr){}

    bool expired() const {
        return cptr->shared_counter > 0;
    }

    shared_ptr<T> lock() const {

    }

    ~weak_ptr(){
        --cptr->weak_counter;
        if(cptr->shared_counter ==0 && cptr->weak_counter ==0) {
            //deallocate                
        }
    }

};

int main(){


    auto sp = make_shared<S>(5,"abc");
    shared_ptr<int> ssp = p;

}