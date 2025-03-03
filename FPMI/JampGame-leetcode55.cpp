#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (i<nums.size())
        {   
            if((nums[i]==0 || nums[i]==1) && nums.size() ==1)
                return true;
            else if(nums[i]==0 && nums.size()>1)
                return false;

                i+=nums[i];

            if(i >= nums.size()-1)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {2,3,1,1,4};
    cout << sol.canJump(tmp) << endl;

}