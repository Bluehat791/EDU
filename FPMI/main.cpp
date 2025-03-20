#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<unordered_map<char,int>> all_hash(vector<string>& strs)
    {
        vector<unordered_map<char,int>> tmp;
        for (size_t i = 0; i < strs.size(); i++)
        {
            unordered_map<char,int> hash;
            for (size_t j = 0; j < strs[i].size(); j++)
            {
                hash[strs[i][j]]++;
            }
            if (auto iter = find(tmp.begin(),tmp.end(),hash);iter==tmp.end())
            {
                tmp.push_back(hash);
            }
            
        }
        return tmp;
    }

    bool equal_hash(unordered_map<char,int> hash, string s)
    {   
        
        for (size_t i = 0; i < s.size(); i++)
        {
            if (hash.insert({s[i],0}).second)
            {
                return false;
            }
            
        }
        if (hash.size()==0 && s.size()==0)
        {
            return true;
        } else if(hash.size()!=0 && s.size()==0)
        {
            return false;
        }
        
        
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char,int>> hash = all_hash(strs);
        vector<vector<string>> result;
        for (size_t i = 0; i < hash.size(); i++)
        {
            vector<string> tmp;
            for (size_t j = 0; j < strs.size(); j++)
            {
                if (equal_hash(hash[i],strs[j]))
                {
                    tmp.push_back(strs[j]);
                }
                
            }
            result.push_back(tmp);
        }
         
        sort(result.begin(),result.end(),[](vector<string> x,vector<string> y){
                return x.size()<y.size();
            });
        
        return result;
    }
};

int main()
{
    Solution sol;

    vector<string> strs= {"","b"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
}