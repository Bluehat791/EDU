#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0)
        {
            return {};
        }
        
        vector<string> result;
        int first = nums[0];
        int value = nums[0];
        string s = "";
        for (size_t i = 1; i < nums.size(); i++)
        {
            if ((nums[i]-value)<2)
            {
                value = nums[i];
            } else
            {   
                if(first!=value)
                {
                    s = to_string(first) + "->" + to_string(value); 
                } else 
                {
                    s = to_string(first);
                }

                first = nums[i];
                value = nums[i];
                result.push_back(s);
            }
        }

        if(first!=value)
        {
            s = to_string(first) + "->" + to_string(value); 
        } else 
        {
            s = to_string(first);
        }
        result.push_back(s);
        
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,2,3,4,6,8,9};
    sol.summaryRanges(nums);
}