#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (size_t i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];
            int x = count_if(strs.begin(),strs.end(),[&tmp,&i](string s){ return s[i]==tmp;});
            if (x<strs.size())
            {
                return result;
            }else
            {
                result+=tmp;
            }
            
        }
        return result;
    }
};


int main()
{
    Solution sol;
    vector<string> tmp {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(tmp) << endl; 
}