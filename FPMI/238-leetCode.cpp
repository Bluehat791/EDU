#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
 
            int left =1;
            for (int i = 0; i < nums.size(); i++)
            {
                result[i]*=left;
                left*=nums[i];
            }

            int right =1;
            for (int i = nums.size()-1; i >=0; i--)
            {
                result[i]*=right;
                right*=nums[i];
            }
            
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {1,2,3,4};
    vector<int> tmp2 = sol.productExceptSelf(tmp);

    for (const auto& i : tmp2)
    {
        cout << i << " ";
    }
    
    cout << "\n";
}