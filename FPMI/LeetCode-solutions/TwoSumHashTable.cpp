#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;

        for (int i = 0; i < nums.size(); i++)
        {   
            int complete = target - nums[i];
            if (numMap.find(complete)!=numMap.end())
            {
                return {numMap[complete],i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main()
{

}