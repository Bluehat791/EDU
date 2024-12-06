#include<bits/stdc++.h>
using namespace std;
vector<int> A,ST;

void build(int node,int L, int R)
{
    if(L==R)
        ST[node] = A[L];
    else {


        int mid = (L+R)/2;

        build(2*node, L, mid);

        build(2*node+1,mid+1,R);

        ST[node] = ST[2*node]+ ST[2*node +1];
    }
}

void update(int node, int L, int R, int idx, int val)
{
    if(L==R){
        A[idx]+=val;
        ST[node]+=val;
    }
    else {
        int mid = (L+R)/2;

        if(L<=idx and idx <= mid)
            update(2*node, L, mid, idx, val);
        else    
            update(2*node + 1, mid+1, R, idx, val);
        
        ST[node] = ST[2*node]+ ST[2*node + 1];
    }
}

int query(int node,int tl, int tr, int l, int r)
{
    if(r<tl or tr < l)
        return 0;

    if(l<=tl and tr <= r)
        return ST[node];
    int tm = (tl + tr)/2;

    return query(2*node, tl, tm, l, r) +  (2*node, tm+1, tr, l, r);
}

int main()
{

    int n = 6;
    A = { 0, 1, 3, 5, -2, 3 };

    ST.resize(4*n);

    build(1,0,n-1);

    cout << "Sum of values in range 0-4 are: "
         << query(1, 0, n - 1, 0, 4) << "\n";


}
