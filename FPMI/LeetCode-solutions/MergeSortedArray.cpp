#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        size_t i = 0,j = 0;
        for (; i < m and j < n;)
        {
            if(nums1[i]<nums2[j])
            {
                tmp.push_back(nums1[i++]);
                continue;
            } else {
               tmp.push_back(nums2[j++]);
                continue; 
            }
            tmp.push_back(nums1[i++]); 
            j++;
        }

        while (i < m)
        {
            tmp.push_back(nums1[i++]);
            continue;
        }

         while (j < n)
        {
            tmp.push_back(nums2[j++]);
            continue; 
        }
        
        
        for(int i = 0; i< nums1.size();i++)
        {   
            if(i<nums1.size())
                nums1[i] = tmp[i];
            else
                nums1.push_back(tmp[i]);
        }
    }
};

int main(){
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    Solution sol;
    sol.merge(nums1,1, nums2, 0);


    cout << "dsdsds\n";
}