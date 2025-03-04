#include <bits/stdc++.h>
using namespace std;


class Solution {
    
public:
    bool canJump(vector<int>& nums) {
        int last_id = nums.size()-1;

        for (size_t i = nums.size()-2; i >=0; i--)
        {
            if(i+nums[i]>=last_id)
                last_id=i;
        }
        return last_id == 0;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {2,0,0};
    cout << sol.canJump(tmp) << endl;

}