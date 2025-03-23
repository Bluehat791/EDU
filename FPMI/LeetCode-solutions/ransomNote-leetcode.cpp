#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_multiset<char> all_ch;
        for (size_t i = 0; i < magazine.size(); i++)
        {
            all_ch.insert(magazine[i]);
        }

        for (size_t i = 0; i < ransomNote.size(); i++)
        {
            if (auto iter = find(all_ch.begin(),all_ch.end(),ransomNote[i]); iter == all_ch.end())
            {
                return false;
            } else{
                all_ch.erase(iter);
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string ransomNote = "aa";
    string magazine = "ab";
    sol.canConstruct(ransomNote,magazine);
}