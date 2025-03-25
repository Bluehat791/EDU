#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> tmp;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!tmp.insert({nums[i],i}).second)
            {
                if (i-tmp[nums[i]]<=k)
                {
                    return true;
                }
                tmp[nums[i]]=i;
            }
            
        }
        
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,0,1,1};
    int k = 1;
    cout << sol.containsNearbyDuplicate(nums,k) << endl;
}