#include <bits/stdc++.h>
using namespace std;


int sum(int idx, vector<int>& F)
{
    int runningSum = 0;
    while (idx>0)
    {
        runningSum +=F[idx];
        int rightMostSetBit = (idx & (-idx));
        idx -= rightMostSetBit;
    }
    return runningSum;
}


void add(int idx, int X, vector<int>& F)
{
    while (idx<F.size())
    {
        F[idx]+=X;
        int rightMostSetBit = (idx & (-idx));
        idx += rightMostSetBit;
    }
}

int rangeQuery(int l, int r, vector<int>& F)
{
    return sum(r,F) - sum(l-1,F);
}

int main(){
    int n = 5;

    vector<int> arr{1,2,3,4,5};

    vector<int> F(n+1,0);

    for (int i = 0; i < n; i++)
    {
        add(i,arr[i], F);
    }
    
    // query the sum from index 1 to 3
    cout << rangeQuery(1, 3, F) << "\n";
    // query the sum from index 2 to 5
    cout << rangeQuery(2, 5, F) << "\n";

    int i = 3;
    int X = 7;
    
    add(i, X - arr[i], F);

    // query the sum from index 1 to 3
    cout << rangeQuery(1, 3, F) << "\n";
    // query the sum from 2 to 5
    cout << rangeQuery(2, 5, F) << "\n";

}