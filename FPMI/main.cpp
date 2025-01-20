#include <bits/stdc++.h>
using namespace std;


void add_edge(int u, int v, vector<vector<int>> &matrix,int winner,vector<bool>& was)
{   
    was[u-1] = true;
    was[v-1] = true;
    if (u == v)
        return;
    if(winner == 1)    
        matrix[u - 1][v - 1] = 1;
    else
        matrix[v - 1][u - 1] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));
    vector<bool> was(n);
    if (n > m)
        cout << "NO";
    else
    {   
        for(int i = 0;i<m;i++) 
        {
            int player1,player2,winner;
            cin >> player1 >> player2 >> winner;
            add_edge(player1,player2,matrix,winner,was);
        }
        int max_elo=0;
        for (size_t i = 0; i < matrix.size(); i++)
        {   
            int count = 0;
            for (size_t j = 0; j < matrix.size(); j++)
            {
                count+=matrix[i][j];
            }
            if(max_elo<count)
                max_elo = count;
        }
        
        int equal = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {   
            int count= 0;
            for (size_t j = 0; j < matrix.size(); j++)
            {
                count+=matrix[i][j];
            }
            if(max_elo==count)
                equal++;
        }

        if(equal>=2)
        {
            cout << "NO";
            return 0;
        }

        for (size_t i = 0; i < was.size(); i++)
        {
            if(was[i] == false)
            {
                cout << "NO";
                return 0;
            }
        }
        

        cout << "YES";
    }
}