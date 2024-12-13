#include <bits/stdc++.h>
using namespace std;

template<unsigned N>
struct Catalan
{   
    long long res = 0;
    static const unsigned value;
    for (size_t i = 0; i < N; i++)
    {
        res +=Catalan<i>::value*Catalan<n-i-1>::value;
    }
    Catalan(){
        for (size_t i = 0; i < N; i++)
        {
            res +=Catalan<i>::value*Catalan<n-i-1>::value;
        }
        static const unsigned value = res;
    }
};

template<>
struct Catalan<0>
{
    static const unsigned value = 1;
};



class Solution {
    vector<int> result;
public:
    Solution()
    {
        // result = { catalan<1>(),catalan<2>(),catalan<3>(),
        // catalan<5>(),catalan<6>(),catalan<7>(),catalan<8>(),
        // catalan<9>(),catalan<10>(),catalan<11>(),catalan<12>(),
        // catalan<13>(),catalan<14>(),catalan<15>(),catalan<16>()
        // };
    }

    int numTrees(int n) {
        // if(n<15)
        //     return result[n];
        // else
            return catalan(n);
    }
};

int main()
{
    Solution sol;
    cout << sol.numTrees(14);
}