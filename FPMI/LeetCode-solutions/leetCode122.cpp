#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (size_t i = 0; i < prices.size()-1; i++)
        {
            if((prices[i+1]-prices[i])>0)
                result+=prices[i+1]-prices[i];
        }
        return result;
    }
};


int main()
{
    Solution sol;

    vector<int> result = {7,6,4,3,1};
    cout << sol.maxProfit(result) << endl;
    return 0;
}