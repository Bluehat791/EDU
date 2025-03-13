#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size()-1;
        while (left<right)
        {
            long current_v = min(height[left],height[right])*(right-left);
            if (current_v>max_water)
            {
                max_water = current_v;
            }
            height[left]>height[right]?right--:left++;
        }
        return max_water;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(tmp) << endl;
}