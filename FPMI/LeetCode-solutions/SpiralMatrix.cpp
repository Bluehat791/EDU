#include <bits/stdc++.h>
using namespace std;

class Solution {

    class magic_var
    {   
        int border;
        int min_border;
        void increment()
        {
            x++;
        }
        void decrement()
        {
            x--;
        }
        bool cols;
        int switch_count = 0;
    public:
        
        bool static_var;
        bool flag;
        int x;
        magic_var(int x_,int border_,bool cols_=false,bool flag_ = true,int min_border_=0)
            : x(x_),border(border_),flag(flag_),min_border(min_border_),cols(cols_)
        {
            if(border==0)
            {
                static_var = true;
            }
        }

        magic_var& operator++(int)
        {
            if(!static_var){
            if (flag)
            {
                increment();
                if (x==border)
                {
                    flag = false;   
                    if(cols && switch_count == 0)
                    {

                    } else
                    {
                        min_border++;
                    }
                    
                    switch_count++;
                }
                
            } else
            {
                decrement();
                if(x==min_border)
                {   
                    flag = true;
                    if (cols && switch_count<1)
                    {
                        
                    }else
                    {
                        border--;
                    }
                    
                    switch_count++;    
                }
            }
            }
            return *this;
        }
    };
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int result_size = matrix[0].size() * matrix.size();
        magic_var cols(0,matrix[0].size()-1,true);
        magic_var rows(0,matrix.size()-1);
        while (result.size()<result_size)
        {
            
            
            if(result.empty())
            {

            }
            else if(cols.flag && rows.flag && !cols.static_var)
            {
                cols++;
            } else if(!cols.flag && rows.flag && !rows.static_var)
            {
                rows++;
            } else if(!cols.flag && !rows.flag && !cols.static_var)
            {
                cols++;
            } else
            {
                rows++;
            }

            result.push_back(matrix[rows.x][cols.x]);
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tmp = {{1,2,3},{4,5,6},{7,8,9}};
    sol.spiralOrder(tmp);
}