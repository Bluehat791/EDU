#include <bits/stdc++.h>
using namespace std;

void displayMatrix(int v, vector<vector<int>>& matrix)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for(j=0;j<v;j++)
        {
            cout << matrix[i][j] << " ";
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
        while(cin>>input)
        {   
            tmp.push_back(input);
            
            if(cin.peek() == '\n')
                break;
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

    displayMatrix(n,matrix);

}