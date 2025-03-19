#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> wordHelper(string s)
    {   
        string second_s = s;
        vector<string> result;
        string_view sv = second_s;
        while (!sv.empty())
        {
            size_t index = s.find(' ');
            if (index == string::npos)
            {
                result.push_back(s);
                break;
            } else
            {
                string tmp(s.begin(),s.begin()+index);
                result.push_back(tmp);
                sv.remove_prefix(index+1);
                s = sv;
            }
            
        }
        return result;
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        vector<string> s_word = wordHelper(s);
        if (s_word.size()!=pattern.size())
        {
            return false;
        }
        
        for (size_t i = 0; i < pattern.size(); i++)
        {   
            if (auto iter = find_if(map.begin(),map.end(),[=](pair<char,string> x){
                return x.second == s_word[i];
            });iter!=map.end())
            {
                if (iter->first!=pattern[i])
                {
                    return false;
                }
                
            }
            
            if (!map.insert({pattern[i],s_word[i]}).second)
            {
                if(map[pattern[i]]!=s_word[i])
                    return false;
            }
            
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string pattern = "abba";
    string s = "dog dog dog dog";
    cout << sol.wordPattern(pattern,s) << endl;
}