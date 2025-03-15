#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool trueSubstring(string range_view,vector<string> words)
    {   
        int size_s = words[0].size();
        vector<string> tmp;
        int left = 0;
        int right = size_s;
        while (right<=range_view.size())
        {
            tmp.push_back(range_view.substr(left,right-left));
            left+=size_s;
            right+=size_s;
        }
        
        for (size_t i = 0; i < words.size(); i++)
        {
            if (auto iter = find(tmp.begin(),tmp.end(),words[i]);iter==tmp.end())
            {
                return false;
            }
            else
            {
                words[i]= "";
                *iter = "-";
            }
        }
        
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        for (size_t i = 0; i < words.size(); i++)
        {
            if(auto x = s.find(words[i],0);x==string::npos)
            {
                return vector<int>{};
            }
            
        }
        vector<int> result;

        int left = 0;
        int right = words.size()*words[0].size();
        while (right<=s.size())
        {   
            string  range_view(s.data()+left,right-left);
            if (trueSubstring(range_view,words))
            {
                result.push_back(left);
            }
            
            left++;
            right++;
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "";
    vector<string> tmp = {};
    vector<int> result = sol.findSubstring(s,tmp);
}