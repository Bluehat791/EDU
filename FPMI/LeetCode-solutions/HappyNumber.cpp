#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sum_pow(int n)
    {   
        int result = 0;
        while (n > 0)
        {
            int digit = n%10;
            result+=pow(digit,2);
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end())
        {
            seen.insert(n);
            n = sum_pow(n);
        }
        return n==1;
    }
};

int main()
{
    Solution sol;
    int n = 2;
    cout << sol.isHappy(n) << endl;
}