#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(),nums.end(),val),nums.end());
        return nums.size();
    }
};

int main()
{   
    Solution sol;
    vector<int> tmp = {0,1,2,2,3,0,4,2};
    std::cout << sol.removeElement(tmp,2) << "\n";
}
