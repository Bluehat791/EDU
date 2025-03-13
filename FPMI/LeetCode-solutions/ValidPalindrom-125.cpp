#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> extra_char;
        for (size_t i = 0; i < s.size(); i++)
        {
            if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)||(s[i]>=48 && s[i]<=57))
            {
                if (isupper(s[i]))
                {
                    s[i]=tolower(s[i]);
                }
                
            } else{
                extra_char.push_back(s[i]);
            }
        }

        for (size_t i = 0; i < extra_char.size(); i++)
        {
            s.erase(remove(s.begin(),s.end(),extra_char[i]),s.end());
        }
        
        string s2 =s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
};

int main()
{
    Solution sol;
    string s = "0P";
    cout << sol.isPalindrome(s) << endl;
}