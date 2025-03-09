#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<char,int>> default_s { 
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
    vector<pair<string,int>> castom_s {
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900},
        };
    
    int castom_helper(char& one, char& two)
    {
        string s = "";
        s+=one;
        s+=two;

        if(auto iter = find_if(castom_s.begin(),castom_s.end(),[s](pair<string,int> x){
            return s==x.first;
        }); iter != castom_s.end())
        {
            return iter->second;
        }

        return 0;
    }

    int default_helper(char& one)
    {
        if(auto iter = find_if(default_s.begin(),default_s.end(),[one](pair<char,int> x){
            return one==x.first;
        }); iter != default_s.end())
        {
            return iter->second;
        }
        return 0;
    }

public:
    int romanToInt(string s) {
        int result=0;
        for (size_t i = 0; i < s.size(); i++)
        {   
            int tmp;
            if(i!=s.size()-1)
            {
                tmp = castom_helper(s[i],s[i+1]);
                if(tmp)
                {
                    result+=tmp;
                    i++;
                    continue;
                }
            }

            tmp = default_helper(s[i]);
            if (tmp)
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
    string s = "MCMXCIV";
    cout << sol.romanToInt(s) << endl;
}