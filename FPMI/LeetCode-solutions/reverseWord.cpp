#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string reverseWords(string s) {
        stack<char> tmp;
        string result;
        for (auto iter = s.rbegin();iter!=s.rend();iter++)
        {
            if(*iter==' ')
            {
                while (!tmp.empty())
                {
                    result+=tmp.top();
                    tmp.pop();

                }
                if(!result.empty())
                    if(result[result.size()-1]!=' ')
                        result+=' ';
            } else{
                tmp.push(*iter);
            }
        }
        while (!tmp.empty())
        {   
            if(tmp.top()!=' ')
                result+=tmp.top();
            tmp.pop();
        }
        if (result[result.size()-1]==' ')
        {
            result.pop_back();
        }
        
        return result;
    }
};


int main()
{
    Solution sol;
    string s = "  hello world  ";
    cout << sol.reverseWords(s) << endl;
    return 0;
}