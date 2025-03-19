#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (size_t r = 0; r < 9; r++)
        {
            for (size_t c = 0; c < 9; c++)
            {
                if(board[r][c]=='.')
                    continue;

                char value = board[r][c];
                int boxIndex = (r/3)*3 + (c/3);

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value))
                {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
                
            }
        }
        return true;
    }
};


int main()
{
    Solution sol;
    vector<vector<char>> tmp = {{'.','.','4','.','.','.','6','3','.'},{'.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','9','.'},{'.','.','.','5','6','.','.','.','.'},{'4','.','3','.','.','.','.','.','1'},{'.','.','.','7','.','.','.','.','.'},{'.','.','.','5','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'}};

    cout << sol.isValidSudoku(tmp) << endl;
}