#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    ll value;
     Node *L, *R;
};

Node* getnode()
{
    Node* temp = new Node;
    temp->value = 0;
    temp->L = nullptr;
    temp->R = nullptr;
    return temp;
};

Node* root;

void UpdateHelper(Node* curr, ll index,ll L, ll R, ll val )
{
    if(L>index || R<index)
        return;

    if(L==R and L==index){
        curr->value = val;
        return;
    }

    ll mid = L-(L-R)/2;
    ll sum1 =0, sum2 = 0;

    if(index <=mid){

        if(curr->L == nullptr)
            curr->L = getnode();

        UpdateHelper(curr->L, index, L, mid, val);
    }
    else {
        if(curr->R == nullptr)
            curr->R = getnode();

        UpdateHelper(curr->R, index, mid + 1, R, val);
    }

    if(curr->L)
        sum1 = curr->L->value;

    if(curr->R)
        sum2 = curr->R->value;    
    
    curr->value = sum1 + sum2;
    return;
}

ll queryHelper(Node* curr, ll a, ll b, ll L, ll R)
{

    if(curr == nullptr)
        return 0;

    if(L>b or R<a)
        return 0;
    
    if(L>=a and R<=b)
        return curr->value;
    
    ll mid = L-(L-R)/2;

    return queryHelper(curr->L, a, b, L, mid) + queryHelper(curr->R, a, b , mid+1, R);
}

ll query(int L, int R)
{
    return queryHelper(root,L,R,1,10);
}

void update(int index, int value)
{
    UpdateHelper(root, index, 1, 10, value);
}

void operations()
{
    root = getnode();

    update(1, 10);

    update(3,5);

    cout << query(2,8) << endl;

    cout << query(1,10) << endl;

}

int main()
{
    operations();

    return 0;
}