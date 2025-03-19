#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> neighbors(vector<vector<int>>& board,int& i,int& j)
    {   
        vector<bool> result;
        for (int rows = 0; rows < board.size(); rows++)
        {
            for (int cols = 0; cols < board[0].size(); cols++)
            {
                if((abs(rows-i)<2) && (abs(cols-j)<2))
                {   
                    if(cols == j && rows==i)
                        continue;
                    else
                        result.push_back(board[rows][cols]);
                }
            }
        }
        return result;
    }

    void life_cell_helper(vector<vector<int>>& helper,vector<vector<int>>& board,int& i,int& j)
    {
        vector<bool> neighbor = neighbors(board,i,j);
        int sum = reduce(neighbor.begin(),neighbor.end());

        if (sum<2)
        {
            helper[i][j]=0;
        } else if (sum>3)
        {
            helper[i][j]=0;
        }
        
         
    }
    void dead_cell_helper(vector<vector<int>>& helper,vector<vector<int>>& board,int& i,int& j)
    {
        vector<bool> neighbor = neighbors(board,i,j);
        auto sum = reduce(neighbor.begin(),neighbor.end());
        if (sum==3)
        {
            helper[i][j]=1;
        }
        
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> helper = board;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j]==1)
                {
                    life_cell_helper(helper,board,i,j);
                } else {
                    dead_cell_helper(helper,board,i,j);
                }   
            }
        }
        
        board = helper;
        cout << "true";
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix{{1,1},{1,0}};
    sol.gameOfLife(matrix);
}