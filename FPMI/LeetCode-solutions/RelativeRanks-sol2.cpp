#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    using int2 = pair<int,int>;
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int2> sIdx(n);
        for(int i =0;i<n;i++)
            sIdx[i] = {score[i], i};
        sort(sIdx.rbegin(), sIdx.rend());
        vector<string> result(n);
        result[sIdx[0].second] = "Gold Medal";
        if (n>1)
        {
            result[sIdx[1].second] = "Silver Medal";
        }
        if (n>2)
        {
            result[sIdx[2].second] = "Bronze Medal";
        }
        for(int i = 3;i<n;i++)
            result[sIdx[i].second] = to_string(i+1);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> ivec = {10,3,8,9,4};
    vector<string> vec = sol.findRelativeRanks(ivec);
    for(const auto& m : vec)
        cout << m << " ";
    cout << '\n';
}