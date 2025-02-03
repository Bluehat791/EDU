#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<bool> v;
vector<vector<int>> g;

void edge(int a ,int b)
{
    g[a].pb(b);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    v[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for(auto i = g[f].begin(); i!=g[f].end();i++)
        {
            if(!v[*i])
            {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
    
}