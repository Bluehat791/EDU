#include <bits/stdc++.h>
using namespace std;

class Solution {
    void findAllConcatenation(unordered_set<string>& all,vector<string>& word)
    {   
        vector<int> tmp;
        for (size_t i = 0; i < word.size(); i++)
        {
            tmp.push_back(i);
        }
        
        vector<vector<int>> comb;

        do {
            comb.push_back(tmp);
        } while (std::next_permutation(tmp.begin(), tmp.end()));

        for (size_t i = 0; i < comb.size(); i++)
        {
            string s = "";
            for (size_t j = 0; j < comb[0].size(); j++)
            {
                s+=word[comb[i][j]];
            }
            all.insert(s);
        }
    }

    void findAllOccurrences(const std::string& text, const std::string& pattern, unordered_set<int>& result) {
        size_t pos = text.find(pattern, 0); // Начинаем поиск с позиции 0

        while (pos != std::string::npos) {
          result.insert(pos);
          pos = text.find(pattern, pos + 1); // Ищем следующее вхождение, начиная с позиции после текущего
        }

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
        
        unordered_set<string> all_word;
        findAllConcatenation(all_word,words);
        unordered_set<int> result;
        for (auto iter = all_word.begin();iter!=all_word.end();iter++)
        {   
            findAllOccurrences(s,*iter,result);
        }
        if (result.empty())
        {
            return vector<int>{};
        }
        //result.erase(unique(result.begin(),result.end()),result.end());
        vector<int> true_result(result.begin(),result.end());

        return true_result;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    vector<string> tmp = {"a","a"};
    vector<int> result = sol.findSubstring(s,tmp);
}