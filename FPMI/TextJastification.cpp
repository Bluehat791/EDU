#include <bits/stdc++.h>
using namespace std;

class Solution {
    void added_space(string& s, int Width,bool last_str)
    {   
        if(!last_str)
        {
            vector<int> index_space;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i]==' ')
                {
                    index_space.push_back(i);
                }
            }
            if(index_space.empty())
            {   
                added_space(s,Width,true);
                return;
            }
            int index = 0;
            while (s.size()!=Width)
            {   
                if (index==index_space.size())
                {
                    index=0;
                }

                s.insert(index_space[index],1,' ');
                
                for (size_t i = index; i < index_space.size(); i++)
                {
                    index_space[i]++;
                }
                
                index++;
            }
        } else{
            while(s.size()!=Width)
                s+=' ';
        }
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string s = "";
        for (size_t i = 0; i < words.size(); i++)
        {
            if (s=="" && (s.size()+words[i].size()<=maxWidth))
            {   
                s+=words[i];
            }else if(s.size()+1+words[i].size()<=maxWidth)
            {   
                s+=' ';
                s+=words[i];
            } else {
                if (i!=words.size())
                {
                    added_space(s,maxWidth,false);
                    result.push_back(s);
                    s.clear();
                    i--;
                } else
                {
                    added_space(s,maxWidth,true);
                    result.push_back(s);
                    s.clear();
                }
                
            }
        }
        if(!s.empty())
        {
            added_space(s,maxWidth,true);
            result.push_back(s);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> tmp = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> result = sol.fullJustify(tmp,20);

    cout << "ojt\n";
}