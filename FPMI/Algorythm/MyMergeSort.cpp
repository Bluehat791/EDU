#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    void merge(vector<int>& nums,int& left, int middle, int& right){
        vector<int> tmp(right - left +1);

        int l = left;
        int r = middle+1;

        int k=0;
        while (l<=middle&&r<=right)
        {
            if(nums[l]<=nums[r]) tmp[k++] = nums[l++];
            else tmp[k++] = nums[r++];
        }

        while(l<=middle) tmp[k++] = nums[l++];
        while(r<=right) tmp[k++] = nums[r++];
        
        for (size_t i = 0; i < k; i++)
        {
            nums[left+i] = tmp[i];
        }
        
    }
    void mergeSort(vector<int>& nums,int left, int right){
        if(left>=right) return;

        int m = left + (right - left)/2;
        mergeSort(nums,left,m);
        mergeSort(nums,m+1,right);
        merge(nums,left, m, right);
    }
    
    vector<int> sortArray(vector<int>& nums){
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

int main(){
    vector<int> nums{6,5,3,1,8,7,2,4};
    Solution sol;
    sol.sortArray(nums);

    for(const auto& m: nums)
    cout << m << "\n";
}