#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> mergeTwoArr(vector<int>& nums1,vector<int>& nums2)
    {
        return {nums1[0],nums2[nums2.size()-1]};
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size()==0)
        {
            return {};
        }
        if (intervals.size()==1)
        {
            return intervals;
        }
        
        vector<vector<int>> result;

        vector<int> value = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0]<=value[value.size()-1] && value[value.size()-1]<intervals[i][intervals[i].size()-1])
            {
                result.push_back(mergeTwoArr(value,intervals[i]));
            } else
            {
                result.push_back(intervals[i]);
            }
            value = intervals[i];
        }

        result.push_back(value);
        

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,4},{5,6}};
    sol.merge(intervals);
}