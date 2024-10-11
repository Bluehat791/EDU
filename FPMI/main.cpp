#include <iostream>
#include <array>

//non_types templates parameters

template<typename T, size_t N>
class array {
    T a[N];
public:

};

template<typename T, T* P>
struct MyStruct {

};

template<typename Field,size_t M, size_t N>
class Matrix {

};

template<typename Field,size_t M,size_t N,size_t K>
Matrix<Field,M,K> operator*(const Matrix<Field,M,N>&,const Matrix<Field,N,K>&);


int main() {
    std::array<int,10> a;
   // std::array<int,15> b = a;

    return 0;
} 