#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> s_hash;
        unordered_map<char,int> t_hash;

        for (size_t i = 0; i < s.size(); i++)
        {
            if(s_hash.find(s[i])==s_hash.end())
            {
                s_hash[s[i]] = i;
            }

            if(t_hash.find(t[i])==t_hash.end())
            {
                t_hash[t[i]] = i;
            }

            if (s_hash[s[i]]!=t_hash[t[i]])
            {
                return false;
            }
            
        }
        
        return true;
    }
};

int main()
{

}