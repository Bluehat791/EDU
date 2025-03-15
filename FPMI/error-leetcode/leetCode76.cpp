#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool have_all_char(list<pair<char,int>> tmp, unordered_map<char,int> charCount)
    {
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if(auto iter = charCount.find(tmp[i]);iter!=charCount.end())
            {   
                if (iter->second!=0)
                {
                    iter->second--;
                }
            }
        }
        
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
            return "";

        unordered_map<char,int> charCount;
        for (char ch : t)
        {
            charCount[ch]++;
        }

        list<pair<char,int>> tmp_list;
        for (int i = 0; i < s.size(); i++)
        {
            tmp_list.push_front({s[i],i});
        }
        
        for (auto iter = tmp_list.begin();iter!=tmp_list.end();iter++)
        {
            if(charCount.find(iter->first)==charCount.end())
            {
                tmp_list.erase(iter);
                iter = tmp_list.begin();
            }
        }
        
        int left = 0;
        int right = t.size();
        while (right<tmp_list.size())
        {
            /* code */
        }
        
        
        
        return "";
    }
};

int main()
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s,t) << endl;
}