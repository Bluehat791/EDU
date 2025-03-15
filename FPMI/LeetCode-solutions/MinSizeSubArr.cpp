#include <bits/stdc++.h>
using namespace std;

class Solution {
        std::vector<int> calculatePrefixSum(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefixSum(n);

        if (n > 0) {
          prefixSum[0] = arr[0];
          for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
          }
        }

        return prefixSum;
    }

    int calculateRangeSum(const std::vector<int>& prefixSum, int i, int j) {
          if (i < 0 || j >= prefixSum.size() || i > j) {
            std::cerr << "Invalid range" << std::endl;
            return 0; // Или можно выбросить исключение
          }

          if (i == 0) {
            return prefixSum[j];
          } else {
            return prefixSum[j] - prefixSum[i - 1];
          }
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(auto iter = find_if(nums.begin(),nums.end(),[&target](int x){return x>=target;});iter!=nums.end())
        {
            return 1;
        }
        vector<int> prefixSum = calculatePrefixSum(nums);
        int min_size = INT_MAX;
        int left = 0;
        int right = left+1;
        while (right<nums.size())
        {   
            int total = calculateRangeSum(prefixSum,left,right);
            if (total>=target)
            {
                int size = right - left;
                if (size<min_size)
                {
                    min_size=size;
                }
                left++;  
            } else if(total>target)
            {
                left++;
            } else
                right++;
        }
        
        return min_size==INT_MAX?0:min_size+1;
    }
};

int main()
{
    Solution sol;
    int target = 11;
    vector<int> nums = {1,2,3,4,5};
    cout << sol.minSubArrayLen(target,nums);
}