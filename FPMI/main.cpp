#include <bits/stdc++.h>
using namespace std;

class Solution {
    //a class for counting filled squares on each row
    class filling_square
    {
        int filling = 0;
        bool open = false;
        int size_squares =0;
    public:
        void insert(int value)
        {
            if(value == 1 && open==false)
            {
                open=true;
            } else if(value==1 && open==true)
            {
                filling+=size_squares;
                size_squares=0;
            } else if(value == 0 && open == true)
            {
                size_squares++;
            }
        }

        int get_filling_squares()
        {
            return filling;
        }

        void close_row()
        {
            open = false;
            size_squares=0;
        }
    };

public:
    int trap(vector<int>& height) {
        filling_square fl;
        size_t size = *max_element(height.begin(),height.end());
        vector<vector<int>> matrix(size,vector<int>(height.size(),0));

        //deleting unnecessary rows of the matrix
        for (size_t i = size; i>0; i--)
        {   
            int count = std::count_if(height.begin(),height.end(),[i](int x){return x>=i;});
            if(count<2)
                matrix.pop_back();
            else
                break;
        }

        //filling the matrix with units
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < height.size(); j++)
            {
                if(height[j]>=i+1)
                    matrix[i][j]=1;
            } 
        }
        
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < height.size(); j++)
            {
                fl.insert(matrix[i][j]);
            }
            fl.close_row();
        }
        
        return fl.get_filling_squares();
    }
};

int main()
{
    Solution sol;
    vector<int> heigh = {4,2,0,3,2,5};
    cout << sol.trap(heigh) << endl;
}