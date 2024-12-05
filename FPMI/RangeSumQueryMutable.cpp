#include <bits/stdc++.h>
using namespace std;

// 



class NumArray {
    vector<int> ST;
    int size_n;

    void build (int node, int L,int R, vector<int>& nums)
    {
        if(L==R){
            ST[node] = nums[L];
            return;
        }

        int mid = (L + R)/2;
        build(2*node+1,L,mid, nums);
        build(2*node+2,mid+1,R, nums);

        ST[node] = ST[2*node+1] + ST[2*node + 2];
    }

    int query(int node, int L, int R, int tl, int tr)
    {
        if(tr<L || R<tl)
        {
            return 0;
        }
        if(tl<=L && R<=tr)
        {
            return ST[node];
        }

        int mid = (L + R)/2;
        int left = query(2*node+1, L, mid, tl,tr);
        int right = query(2*node+2, mid+1, R, tl,tr);

        return left + right;
    }

    void update(int node, int L,int R,int index,int val)
    {
        if(L==R)
        {
            ST[node] = val;
            return;
        }

        int mid = (L + R)/2;
        if(index<=mid)
            update(2*node+1,L,mid,index,val);
        else
            update(2*node+2,mid+1,R,index,val);

        ST[node] = ST[2*node+1] + ST[2*node + 2];    
    }
public:
    NumArray(vector<int>& nums){
        size_n = nums.size();
        ST.resize(4*size_n+1);
        build(0,0,size_n-1,nums);
    }
    
    void update(int index, int val) {
        update(0,0,size_n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,size_n-1,left,right);
    }
};

int main(){
    vector<int> tmp = {0,9,5,7,3};
    NumArray numArray(tmp);
    cout << numArray.sumRange(4,4) << endl; // return 1 + 3 + 5 = 9
    //numArray.update(1, 2);   // nums = [1, 2, 5]
    cout << numArray.sumRange(2,4)<< endl; // return 1 + 2 + 5 = 8

    // NumArray* obj = new NumArray(tmp);
    // int param_2 = obj->sumRange(1,5);
    // cout << param_2 << endl;
    // obj->update(1,2);
    // param_2 = obj->sumRange(1,5);
    // cout << param_2 << endl;
}