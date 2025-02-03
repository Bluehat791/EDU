#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> adj[N];

bool visited[N];

void dfs(int s)
{
    if(visited[s])
        return;

    visited[s] = true;
    for(auto u: adj[s])
    {
        dfs(u);
    }
}