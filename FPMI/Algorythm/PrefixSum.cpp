#include<iostream>
#include<vector>
using namespace std;

vector<int> findPrefixSums(vector<int> a){
    int n = a.size();
    vector<int> b(n+1,0);
    for (size_t i = 0; i < n; i++)
    {
        b[i+1] = b[i]+a[i];
    }
    return b;
}


vector<vector<int>> findPrefixSums2D(const vector<vector<int>>& a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> prefix1D(n);
    for (size_t i = 0; i < n; i++)
    {
        prefix1D[i]=findPrefixSums(a[i]);
    }
    vector<vector<int>> prefixSum2D(n+1,vector<int>(m+1,0));
    for (size_t j = 1; j < m; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            prefixSum2D[i+1][j]= prefixSum2D[i][j]+prefix1D[i][j];
        }
        
    }
    return prefixSum2D;
}

int main(){
    vector<int> a{5,4,7,2,2,-1,8};
    vector<int> b = findPrefixSums(a);
    for (size_t i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << '\n';
    }
     
}
