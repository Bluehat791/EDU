#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size()<s.size())
        {
            return false;
        }
        
        for (size_t i = 0; i < s.size(); i++)
        {
            for (size_t j = i; i < t.size(); i++)
            {
                /* code */
            }
            
        }
        
    }
};

int main()
{   
    Solution sol;
    string s;
    string t;

    cout << sol.isSubsequence(s,t) << endl;
}