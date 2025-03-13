#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size()<s.size())
        {
            return false;
        }
        int sp=0;
        int tp=0;
        while (sp<s.size() && tp<t.size())
        {
            if (s[sp]==t[tp])
            {
                sp++;
            }
            tp++;
        }
        
        return sp==s.size();
    }
};

int main()
{   
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";

    cout << sol.isSubsequence(s,t) << endl;
}