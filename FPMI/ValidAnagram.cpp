#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash_s;
        unordered_map<char,int> hash_t;
        if (s.size()!=t.size())
        {
            return false;
        }
        
        for (size_t i = 0; i < s.size(); i++)
        {
            hash_s[s[i]]++;
            hash_t[t[i]]++;
        }
        return hash_s==hash_t;
    }
};


int main()
{
    Solution sol;
    string ransomNote = "rat";
    string magazine = "car";
    cout << sol.isAnagram(ransomNote,magazine) << endl;
}