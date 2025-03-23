#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> ans;

       for (size_t i = 0; i < strs.size(); i++)
       {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            ans[tmp].push_back(strs[i]);
       }
       
       vector<vector<string>> result;
       for (auto& pair : ans)
       {
        result.push_back(pair.second);
       }
       

       return result;
    }
};

int main()
{
    Solution sol;

    vector<string> strs= {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
}