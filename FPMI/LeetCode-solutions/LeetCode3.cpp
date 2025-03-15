#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size = INT_MIN;
        vector<char> tmp;
        for (size_t j = 0; j < s.size(); j++)
        {
            for (size_t i = j; i < s.size(); i++)
            {
                if(auto iter = find(tmp.begin(),tmp.end(),s[i]);iter!=tmp.end())
                {
                    if (static_cast<int>(tmp.size())>max_size)
                    {
                        max_size = tmp.size();
                    }
                    tmp.clear();
                    break;
                } else{
                    tmp.push_back(s[i]);
                }
            }
        }
        if (static_cast<int>(tmp.size())>max_size)
        {
            max_size = tmp.size();
        }
        return max_size==INT_MIN?0:max_size;
    }
};

int main()
{
    Solution sol;
    string s = "dvdf";
    cout << sol.lengthOfLongestSubstring(s) << endl;
}