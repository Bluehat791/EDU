#include<iostream>
#include<vector>
#include <stdexcept>
#include<algorithm>

using namespace std;

template<typename T>
class Heap {
private:
    std::vector<T> heapArray;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    Heap();

    void insert(const T& value);
    T extractTop();
    void remove(const T& value);
    bool isEmpty();

};

template<typename T>
void Heap<T>::heapifyUp(int index){
    int parentIndex = index/2;
    while (index>1 && heapArray[index]<heapArray[parentIndex])
    {
        std::swap(heapArray[index],heapArray[parentIndex]);
        index = parentIndex;
        parentIndex = index/2;
    }
    
}

template<typename T>
void Heap<T>::heapifyDown(int index) {
    int leftChildIndex = 2*index;
    int rightChildIndex = 2*index +1;
    int smallestIndex = index;
    if (leftChildIndex< heapArray.size() && heapArray[leftChildIndex] < heapArray[smallestIndex])
    {
        smallestIndex = leftChildIndex;
    }

    if (rightChildIndex< heapArray.size() && heapArray[rightChildIndex] < heapArray[smallestIndex])
    {
        smallestIndex = rightChildIndex;
    }
    
    if (smallestIndex != index)
    {
        std::swap(heapArray[index], heapArray[smallestIndex]);
        heapifyDown(smallestIndex);
    }
    

}
template <typename T>
bool Heap<T>::isEmpty(){
    return heapArray.size() == 1;
}

template <typename T>
void Heap<T>::remove(const T& value){
    auto it = std::find(heapArray.begin(), heapArray.end(), value);
    if (it == heapArray.end()) {
        throw std::out_of_range("Element not found in the heap");
    }

    int index = std::distance(heapArray.begin(), it);
    heapArray[index] = heapArray.back();
    heapArray.pop_back();

    if (index > 1 && heapArray[index] < heapArray[index/2])
    {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
    
}

template <typename T>
T Heap<T>::extractTop() {
    if(isEmpty()){
        throw std::out_of_range("Heap is empty");
    }

    T top = heapArray[1];
    heapArray[1] = heapArray.back();
    heapArray.pop_back();
    heapifyDown(1);

    return top;
}

template<typename T>
Heap<T>::Heap(){
    heapArray.push_back(T());
}

template<typename T>
void Heap<T>::insert(const T& value){
    heapArray.push_back(value);
    heapifyUp(heapArray.size()-1);
}

class Solution {
private:
    Heap<int> heap;
public:
    
    vector<string> findRelativeRanks(vector<int>& score) {
        
        
    }
};


int main() {
    Solution sol;
    vector<int> ivec = {5,4,3,2,1};
    vector<string> vec = sol.findRelativeRanks(ivec);
    for(const auto& m : vec)
        cout << m << " ";
    cout << '\n';

    return 0;
}