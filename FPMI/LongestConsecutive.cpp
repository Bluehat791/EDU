#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0)
        {
            return 0;
        }
        
        //radixSort(nums);
        sort(nums.begin(),nums.end());
        //unique(nums.begin(),nums.end());
        vector<int> long_sequence;
        int value = nums[0];
        int size = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {   if (value==nums[i])
            {
                continue;
            }
        
            if (abs(nums[i]-value)<2 && abs(nums[i]-value)!=0)
            {
                size++;
            } else
            {
                long_sequence.push_back(size);
                size=1;
            };
            value = nums[i];
        }
        long_sequence.push_back(size);
        return *max_element(long_sequence.begin(),long_sequence.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-8,-4,9,9,4,6,1,-4,-1,6,8};
    cout << sol.longestConsecutive(nums) << endl;
}