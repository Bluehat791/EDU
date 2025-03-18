#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp;
        for (size_t i = 0; i < matrix.size(); i++)
        {   
            vector<int> tmp2;
            for (int j = matrix.size()-1; j>=0;j--)
            {   
                tmp2.push_back(matrix[j][i]);
            }
            tmp.push_back(tmp2);
        }
        matrix.clear();
        matrix = tmp;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
}