#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (size_t i = 0; i+needle.size()-1<haystack.size(); i++)
        {
            if (haystack[i]==needle[0])
            {
                int x = 1;
                for (; x < needle.size(); x++)
                {
                    if (haystack[i+x]!=needle[x])
                    {
                        break;
                    }
                    
                }
                if (x==needle.size())
                {
                    return i;
                }
                
            }
            
        }
        
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "leetcode";
    string needle = "leeto";
    cout << sol.strStr(haystack,needle) << endl;
}