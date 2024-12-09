#include <bits/stdc++.h>
using namespace std;

typedef pair<Node*,Node*> Pair;

struct Node
{
    int key, prior;
    int sum;
    Node* l = nullptr, *r = nullptr;
    Node(int _key) { key = _key, prior=rand();}
};

class Treap {
    Node* root = 0;

    Node* merge (Node* l, Node *r){
        if(!l) return r;
        if(!r) return l;
        if(l->prior > r->prior){
            l->r = merge(l->r, r);
            upd(l);
            return l;
        }
        else {
            r->l = merge(l,r->l);
            upd(l);
            return r;
        }
    }

    Pair split(Node* p, int x){
        if(!p) return Pair(Node(0),Node(0));
        if(p->key <= x){
            Pair q = split(p->r,x);
            p->r = q.first;
            upd(p);
            return {p,q.second};
        }
        else {
            Pair q = split(p->l, x);
            p->l = q.second;
            upd(p);
            return {q.first, p};
        }
    }
    int sum (Node* v) { return v ? v->sum : 0; }
    void upd (Node* v) { v->sum = sum(v->l) + sum(v->r) + v->key; }

    void insert(int x){
        Pair q = split(root,x);
        Node *t = new Node(x);
        root=merge(q.first,merge(t,q.second));
    }

    int sum(int l, int r){
        Pair rq = split(root, r);
        Pair lq = split(rq.first,l);
        int res = sum(lq.second);
        root=merge(lq.first, merge(lq.second, rq.second));
    }
};