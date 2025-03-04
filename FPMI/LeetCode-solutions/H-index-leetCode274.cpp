#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),[](int a, int b){return a>b;});
        int h = 0;
        for (size_t i = 0; i < citations.size(); i++)
        {
            if(i+1<=citations[i])
                h = i+1;
        }
        return h;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {1,3,1};
    cout << sol.hIndex(tmp) << endl;
}