#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

int main()
{
    int N;

    vector<long> Q; 
    vector<long> C;
    long tmp;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin>> tmp;
        Q.push_back(tmp);
    }

    for (size_t i = 0; i < N; i++)
    {
        cin>> tmp;
        C.push_back(tmp);
    }
    
    long A, B;

    cin >> A >> B;


    vector<long> D;
    for (size_t i = 0; i < N; i++)
    {
        tmp = ((C[i]*(B-A))/255)+A;
        D.push_back(tmp);
    }
    
    long long scalarPOW = std::inner_product(Q.begin(),Q.end(), D.begin(), 0LL);
    std::cout << scalarPOW;
    
}