#include <bits/stdc++.h>
using namespace std;

void displayMatrix(int v, vector<vector<int>>& matrix)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for(j=0;j<v;j++)
        {
            cout << matrix[i][j];
            if(j<v-1)
                cout << " ";
        }
        cout << endl;
    }
}

void add_edge(int u,int v,vector<vector<int>>& matrix)
{   
    if(u==v)
        return;
    matrix[u-1][v-1] = 1;
    matrix[v-1][u-1] = 1;
}

void shortest_path(vector<vector<int>>& matrix,vector<vector<int>>& matrix2)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            if(i!=j)
                matrix2[i][j] = 1;
            else
                matrix2[i][j] = 0;
        }
        
    }
    
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>> result;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0;i<m;i++)
    {   
        int input;
        vector<int> tmp;
        cin>>input;
        for (size_t i = 0; i < input; i++)
        {   
            int count;
            cin>>count;
            tmp.push_back(count);
        }
          

        result.push_back(tmp);
    }

    for (size_t i = 0; i < result.size(); i++)
    {   
        for (int j = 0; j<result[i].size()-1;j++)
        {
            add_edge(result[i][j],result[i][j+1],matrix);
        }
        
    }

    vector<vector<int>> matrix2(n, vector<int>(n));

    shortest_path(matrix,matrix2);


    displayMatrix(n,matrix);
    displayMatrix(n,matrix2);

}