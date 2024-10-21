#include <iostream> 
#include <vector>
#include <deque>

using namespace std;
template <typename T, typename Container = std::deque<T>>
class Queue{
public:
    Queue(){}

    const typename Container::const_iterator& front() const {
        return data.front();
    }

    typename Container::iterator& front() {
        return data.front();
    }

    void pop(){
        data.pop();
    }

    void push(T value){
        data.push_back(value);
    }

    size_t size(){
        return data.size();
    }

    bool empty(){
        return data.empty();
    }

    template <typename T2>
    bool operator == (const Queue<T2>& other) const {
        if (this->size() != other.size()) {
            return false;
        }
        for (size_t i = 0; i != this->size(); ++i) {
                if (!(*this)[i] == other[i]) {
                    return false;
                }
        }
        return true;
    }

    template <typename T2>
    bool operator != (const Queue<T2>& other) const {
        if (this->size() != other.size()) {
            return !false;
        }
        for (size_t i = 0; i != this->size(); ++i) {
                if (!(*this)[i] == other[i]) {
                    return true;
                }
        }
        return true;
    }

    T& operator[](size_t x){
        return data.at(x);
    }

    const T& operator[](size_t x) const{
        return data.at(x);
    }

    ~Queue();


private:
    Container data;

};

int main() {

    Queue<int> q;
    for (size_t i = 0; i < 10; i++)
    {
        q.push(i);
    }

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << q[i];
    }

    std::deque<int>::iterator  it = q.front();
    std::cout << *it << '\n';
    std::cout << q.empty() << '\n';
    
}