#include <iostream> 
#include <vector>
#include <deque>


using namespace std;
template <typename T, typename Container = std::deque<T>>
class Queue{
public:
    Queue(){}

    const typename Container::const_reference front() const {
        return data.front();
    }

    typename Container::reference front() {
        return data.front();
    }

    void pop(){
        data.pop_back();
    }

    void push(T value){
        data.push_back(value);
    }

    size_t size() const{
        return data.size();
    }

    bool empty(){
        return data.empty();
    }
    
    
    bool operator == (const Queue<T>& other) const {
        
        return this->data == other.data;
    }

    
    bool operator != (const Queue<T>& other) const {
        return this->data != other.data;
    }

    T& operator[](size_t x){
        return data.at(x);
    }

    const T& operator[](size_t x) const{
        return data.at(x);
    }

    ~Queue(){};


private:
    Container data;

};

int main() {

    // std::queue<int> a;

    Queue<int> q;
    for (size_t i = 0; i < 10; i++)
    {
        q.push(i);
    }

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << q[i];
    }

    Queue<int> q1;
    for (size_t i = 0; i < 11; i++)
    {
        q1.push(i);
    }

    for (size_t i = 0; i < 11; i++)
    {
        std::cout << q1[i];
    }

    cout << (q == q1) << "\n";
    return 0;
}