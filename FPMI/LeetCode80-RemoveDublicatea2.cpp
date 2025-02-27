#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++)
        {   

            if(std::count(nums.begin(),nums.end(),nums[i])>2)
            {
                auto iter = std::find(nums.begin(),nums.end(),nums[i]);
                iter+=2;
                nums.erase(std::remove(iter,nums.end(),nums[i]),nums.end());
                //i=0;
            } 
        }
        return nums.size();
    }
};

int main()
{   
    Solution sol;
    vector<int> tmp = {1,1,1,2,2,3};
    std::cout << sol.removeDuplicates(tmp) << "\n";
}