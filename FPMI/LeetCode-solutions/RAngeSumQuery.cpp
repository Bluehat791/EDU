 #include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> result;
    vector<int> PrefixSums(vector<int> a){
    int n = a.size();
    for (size_t i = 0; i < n; i++)
    {
        result[i+1] = result[i]+a[i];
    }
    return result;
}
public:
    NumArray(vector<int>& nums) : result(nums.size()+1) {
        PrefixSums(nums);
    }
    
    int sumRange(int left, int right) {
        return result[right+1] - result[left];
    }
};

int main(){
    vector<int> tmp = {-2,0,3,-5,2,-1};
    NumArray nm(tmp);

    cout << nm.sumRange(0,2) << " ";
    cout << nm.sumRange(2,5) << " ";
    cout << nm.sumRange(0,5) << " ";
}