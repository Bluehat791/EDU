#include <bits/stdc++.h>
using namespace std;

class Solution {
    void verticalZero(vector<vector<int>>& matrix,int index)
    {   
        for (size_t i = 0; i < matrix.size(); i++)
        {
            matrix[i][index]=0;
        }
        
    }
    void horizontalZero(vector<vector<int>>& matrix,int index)
    {
        int size = matrix[0].size();
        for (size_t i = 0; i < size; i++)
        {
            matrix[index][i]=0;
        }
        
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zero_i;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j]==0)
                {
                    zero_i.push_back({i,j});
                }
                
            }
        }

        for (size_t i = 0; i < zero_i.size(); i++)
        {
            verticalZero(matrix,zero_i[i].second);
            horizontalZero(matrix,zero_i[i].first);
        }
        
        
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
}