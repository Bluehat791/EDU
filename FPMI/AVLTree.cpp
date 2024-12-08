#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>tree;
    void build(int node,int start,int end) {
        if(start==end) {
            tree[node]=1; 
            return;
        }
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }

    int query(int node,int start,int end, int k) {
        if(start==end) {
            return start;
        }
        int mid=(start+end)/2;
        int left=tree[2*node];
        int right=tree[2*node+1];
        if(k>left){
            return query(2*node+1,mid+1,end, k-left);
        }else{
            return query(2*node,start,mid,k);
        }
    }

    void update(int node,int start,int end,int idx) {
        if(start==end) {
            tree[node]=0; 
            return;
        }
        int mid=(start+end)/2;
        if(idx<=mid){
            update(2*node,start,mid,idx);
        }else{
            update(2*node+1,mid+1,end,idx);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int>a,vector<int>b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        int n=people.size();
        tree.clear();
        tree.resize(4*n+10);
        vector<vector<int>> res(people.size(), vector<int>());
        build(1,0,n-1);
        for(int i = 0; i < people.size(); i++){
            int j=query(1,0,n-1,people[i][1]+1);
            res[j]=people[i];
            update(1,0,n-1,j);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tmp = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    vector<vector<int>> res = sol.reconstructQueue(tmp);

    cout << "fsffsf\n";
}