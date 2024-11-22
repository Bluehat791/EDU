#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void countSort(vector<int>& nums, const int& exp){
        int count[10] = {0};
        vector<int> tmp(nums.size());
        int i;

        for(i=0;i<10;i++)
            count[(nums[i]/exp)%10]++;
        
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        for (i = nums.size() - 1; i >= 0; i--) {
            tmp[count[(nums[i] / exp) % 10] - 1] = nums[i];
            count[(nums[i]  / exp) % 10]--;
        }

        for (i = 0; i < nums.size(); i++)
            nums[i] = tmp[i];
    }
    int getMax(vector<int>& nums){
        int mx = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (mx<nums[i])
            {
                mx = nums[i];
            }
            
        }
        return mx;
    }
    void sortArray(vector<int>& nums){

        int mx = getMax(nums);

        for(int exp = 1;mx/exp!=0;exp*=10)
            countSort(nums,exp);

    }
};


int main(){
    vector<int> nums{ 170, 45, 75, 90, 802, 24, 2, 66};
    Solution sol;
    sol.sortArray(nums);

    for(const auto& m: nums)
    cout << m << "\n";
}