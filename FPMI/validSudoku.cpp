#include <bits/stdc++.h>
using namespace std;

class Solution {
    class sudoku_board
    {   
    public:
        static unordered_set<char,pair<int,int>> all_squares;
    public:
        struct backet
        {
            unordered_map<char,pair<int,int>> squares;
            bool insert(char& x , int i, int j)
            {   
                if (x=='.')
                {
                    return true;
                }
                
                if (auto iter = find_if(squares.begin(),squares.end(),[&x](pair<char,pair<int,int>> value){ return value.first == x; });iter !=squares.end())
                {
                    return false;
                }

                squares.insert({x,{i,j}});
                all_squares.insert({x,{i,j}});
                if (!tmp.second)
                {
                    return false;
                }
                
                
                return true;
            }

            bool operator==(const backet& other)
            {
                return this->squares == other.squares;
            }
            
        };

        vector<backet> backets;

        sudoku_board()
        {
            backets.resize(9);
            
        }
    };
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        sudoku_board s_board;
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                if(i<3&&j<3)
                {
                    if(!(s_board.backets[0].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if (i<3 && (j>2 && j < 6))
                {
                    if(!(s_board.backets[1].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i<3 && (j>5 && j<9 ))
                {
                    if(!(s_board.backets[2].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>2 && i < 6 && j<3)
                {
                    if(!(s_board.backets[3].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>2 && i < 6 && (j>2 && j < 6))
                {
                    if(!(s_board.backets[4].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>2 && i < 6  && (j>5 && j<9 ))
                {
                    if(!(s_board.backets[5].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>5 && i<9  && j<3)
                {
                    if(!(s_board.backets[6].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>5 && i<9  && (j>2 && j < 6))
                {
                    if(!(s_board.backets[7].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                } else if(i>5 && i<9  && (j>5 && j<9 ))
                {
                    if(!(s_board.backets[8].insert(board[i][j],i,j)))
                    {
                        return false;
                    }
                }
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