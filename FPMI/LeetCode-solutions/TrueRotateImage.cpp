#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        int first = 0;
        int last_i = matrix.size()-1;

        //vertical swap
        while (last_i>first)
        {

            swap(matrix[first],matrix[last_i]);            
            last_i--;
            first++;
        }
        
        for (size_t i = 0,j=0; i < matrix.size(); i++,j++)
        {
            int right = j+1;
            int down = i+1;
            while (right<matrix.size())
            {
                swap(matrix[i][right],matrix[down][j]);
                right++;
                down++;
            }
        } 
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
}