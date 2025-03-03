#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> majority;
        for (size_t i = 0; i < nums.size(); i++)
        {
            ++majority[nums[i]];
        }
        
        return (std::max_element(majority.begin(),majority.end(),[](const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.second < b.second;
        }))->first;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {2,2,1,1,1,2,2};
    std::cout << sol.majorityElement(tmp) << "\n";
}