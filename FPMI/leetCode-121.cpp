#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MIN;
        int maxPro = 0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxPro = max(maxPro, prices[i]- minPrice);
        }
        return maxPro;
    }
};

int main()
{
    Solution sol;

    vector<int> result = {7,1,5,3,6,4};
    cout << sol.maxProfit(result) << endl;
    return 0;
}