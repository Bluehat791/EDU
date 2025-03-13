#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
        {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow =0;
        bool goingDown = false;

        for(char c: s)
        {
            rows[currentRow]+=c;

            if (currentRow == 0 || currentRow == numRows -1)
            {
                goingDown = !goingDown;
            }
            currentRow +=goingDown ? 1: -1;
        }

        s.clear();

        for(const string& row : rows)
        {
            s+=row;
        } 
        return s;
    }
};

int main()
{

    Solution sol;
    string s = "PAYPALISHIRING";
    int n = 3;
    cout << sol.convert(s,n) << endl;
}