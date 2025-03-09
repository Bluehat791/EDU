#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        find_if(s.rbegin(),s.rend(),[&size](char x)
        {   
            if(x!=' ')
                size++;

            if(size!=0)
                return x==' ';
            else    
                return x == '\0'; 
        });
        return size;
    }
};

int main()
{
    Solution sol;
    string s =  "luffy is still joyboy";
    cout << sol.lengthOfLastWord(s) << endl; 
}