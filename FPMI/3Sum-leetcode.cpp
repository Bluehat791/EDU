#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            int left = i==0?1:0;
            int right = nums.size()-1;
            while (left<right)
            {   
                if(left==i)
                {
                    left++;
                    continue;
                }
                if(right==i)
                {
                    right--;
                    continue;
                }
                if(nums[i]+nums[left]+nums[right]==0)
                {   
                    vector<int> tmp{nums[i],nums[left],nums[right]};
                    sort(tmp.begin(),tmp.end());
                    result.insert(tmp);
                    right--;
                    left++;
                } else if(nums[i]+nums[left]+nums[right]>0)
                {
                    right--;
                } else{
                    left++;
                }
                
            }
            
        }
        vector<vector<int>> result2(result.begin(),result.end());
        return result2;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    vector<vector<int>> result = sol.threeSum(tmp);
}