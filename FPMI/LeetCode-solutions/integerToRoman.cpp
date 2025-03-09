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

    pair<string,int> castom_helper(int& n)
    {
        if(auto iter = find_if(castom_s.rbegin(),castom_s.rend(),[n](pair<string,int> x){
            return (n - x.second)>=0;
        }); iter != castom_s.rend())
        {
            return *iter;
        }
        return {"0",0};
    }

    pair<char,int> default_helper(int& n)
    {
        if(auto iter = find_if(default_s.rbegin(),default_s.rend(),[n](pair<char,int> x){
            return (n - x.second)>=0;
        }); iter != default_s.rend())
        {
            return *iter;
        }
        return {'0',0};
    }
public:
    string intToRoman(int num) {
        string result = "";
        while (num>0)
        {
            string s = to_string(num);
            if(s[0]=='4' || s[0]=='9')
            {
                pair<string,int> tmp = castom_helper(num);
                result+=tmp.first;
                num-=tmp.second;
                continue;
            } else {
                pair<char,int> tmp = default_helper(num);
                result+=tmp.first;
                num-=tmp.second;
            }
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    int num = 1994;
    cout << sol.intToRoman(num) << endl;
}