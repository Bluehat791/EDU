#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct node
{
    int n;
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
    char mark;
    char C;
};

class FibonacciHeap
{
private:
    int nH;
    node *H;
public:
    node* InitializeHeap();
    int Fibonacci_link(node*, node*, node*);
    node* Create_node(int);
    node* Insert(node*, node*);
    node* Union(node*, node*);
    node* Extract_min(node*);
    int Consolidate(node*);
    int Display(node*);
    node* Find(node*,int);
    int Decrease_key(node*,int,int);
    int Delete_key(node*,int);
    int Cut(node*,node*,node*);
    int Cascase_cut(node*,node*);
    FibonacciHeap()
    {
        H = InitializeHeap();
    }
};


node* FibonacciHeap::InitializeHeap()
{
    node* np = nullptr;
    return np;
}

node* FibonacciHeap::Create_node(int value)
{
    node* x = new node;
    x->n = value;
    return x;
}

node* FibonacciHeap::Insert(node* H, node* x)
{
    x->degree = 0;
    x->parent = nullptr;
    x->child = nullptr;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';
    if (H!=nullptr)
    {
        H->left->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        if (x->n < H->n)
        {
            H = x;
        }   
    }
    else
    {
        H = x;
    }
    nH = nH +1;
    return H;
}

int FibonacciHeap::Fibonacci_link(node* H1, node* y, node* z)
{
    y->left->right = y->right;
    y->right->left = y->left;
    if (z->child == nullptr)
    {
        z->child = y;
    }

    y->right = z->child;
    y->left = z->child->left;
    z->child->left->right = y;
    z->child->left = y;
    if (y->n < z->child->n) 
    {
        z->child = y;
    }

    z->degree++;
}

node* FibonacciHeap::Union(node* H1, node* H2)
{
    node* np;
    node* H = InitializeHeap();
    H = H1;
    H->left->right = H2;
    H2->left->right = H;
    np = H->left;
    H->left = H2->left;
    H2->left = np;
    return H;
}

int FibonacciHeap::Display(node* H)
{
    node* p = H;
    if (p==nullptr) 
    {
        cout << "The Heaap is Empty" << endl;
        return 0;
    }
    cout << "The root nodes of Heap are: " << endl;
    do
    {
        cout << p->n;
        p=p->right;
        if (p!=H)
        {
            cout << "--->";
        }
        
    } while (p!=H&& p->right!=nullptr);
    
}

node* FibonacciHeap::Extract_min(node* H1)
{
    node* p;
    node* ptr;
    node* z = H1;
    p=z;
    ptr = z;
    if (z==nullptr)
    {
        return z;
    }
    node* x;
    node* np;
    x=nullptr;
    if (z->child!=nullptr)
    {
        x = z->child;
    }
    
    if (x!=nullptr)
    {
        ptr = x;
        do
        {
            np - x->right;
            H1->left->right = x;
            x->right = H1;
            x->left = H1->left;
            H1->left = x;
            if (x->n < H1->n)
            {
                H1=x;
            }
            x->parent = nullptr;
            x = np;
        } while (np!=ptr);
        
    }
    z->left->right = z->right;
    z->right->left = z->left;
    H1= z->right;
    if (z == z->right && z->child == NULL)
        H = NULL;
    else
    {
        H1 = z->right;
        Consolidate(H1);
    }
    nH = nH - 1;
    return p;
    
}

int FibonacciHeap::Consolidate(node* H1)
{
    int d, i;
    float f = (log(nH)) / (log(2));
    int D = f;
    node* A[D];
    for (i = 0; i <= D; i++)
        A[i] = NULL;
    node* x = H1;
    node* y;
    node* np;
    node* pt = x;
    do
    {
        pt = pt->right;
        d = x->degree;
        while (A[d] != NULL)
        {
            y = A[d];
            if (x->n > y->n)
            {
                np = x;
                x = y;
                y = np;
            }
            if (y == H1)
                H1 = x;
            FibonacciHeap::Fibonacci_link(H1, y, x);
            if (x->right == x)
                H1 = x;
                A[d] = NULL;
            d = d + 1;
        }
        A[d] = x;
        x = x->right;
    }
    while (x != H1);
    H = NULL;
    for (int j = 0; j <= D; j++)
    {
        if (A[j] != NULL)
        {
            A[j]->left = A[j];
            A[j]->right =A[j];
            if (H != NULL)
            {
                (H->left)->right = A[j];
                A[j]->right = H;
                A[j]->left = H->left;
                H->left = A[j];
                if (A[j]->n < H->n)
                H = A[j];
            }
            else
            {
                H = A[j];
            }
            if(H == NULL)
                H = A[j];
            else if (A[j]->n < H->n)
                H = A[j];
        }
    }
}
 
/*
 * Decrease key of Nodes in Fibonnaci Heap
 */
int FibonacciHeap::Decrease_key(node*H1, int x, int k)
{
    node* y;
    if (H1 == NULL)
    {
        cout<<"The Heap is Empty"<<endl;
        return 0;
    }
    node* ptr = Find(H1, x);
    if (ptr == NULL)
    {
        cout<<"Node not found in the Heap"<<endl;
        return 1;
    }
    if (ptr->n < k)
    {
        cout<<"Entered key greater than current key"<<endl;
        return 0;
    }
    ptr->n = k;
    y = ptr->parent;
    if (y != NULL && ptr->n < y->n)
    {
        Cut(H1, ptr, y);
        Cascase_cut(H1, y);
    }
    if (ptr->n < H->n)
        H = ptr;
    return 0;
}
/*
 * Cut Nodes in Fibonnaci Heap
 */
int FibonacciHeap::Cut(node* H1, node* x, node* y)
{
    if (x == x->right)
        y->child = NULL;
    (x->left)->right = x->right;
    (x->right)->left = x->left;
    if (x == y->child)
        y->child = x->right;
    y->degree = y->degree - 1;
    x->right = x;
    x->left = x;
    (H1->left)->right = x;
    x->right = H1;
    x->left = H1->left;
    H1->left = x;
    x->parent = NULL;
    x->mark = 'F';
}
 
/*
 * Cascade Cutting in Fibonnaci Heap
 */
int FibonacciHeap::Cascase_cut(node* H1, node* y)
{
    node* z = y->parent;
    if (z != NULL)
    {
        if (y->mark == 'F')
        {
            y->mark = 'T';
	}
        else
        {
            Cut(H1, y, z);
            Cascase_cut(H1, z);
        }
    }
}
 
/*
 * Find Nodes in Fibonnaci Heap
 */
node* FibonacciHeap::Find(node* H, int k)
{
    node* x = H;
    x->C = 'Y';
    node* p = NULL;
    if (x->n == k)
    {
        p = x;
        x->C = 'N';
        return p;
    }
    if (p == NULL)
    {
        if (x->child != NULL )
            p = Find(x->child, k);
        if ((x->right)->C != 'Y' )
            p = Find(x->right, k);
    }
    x->C = 'N';
    return p;
}
/*
 * Delete Nodes in Fibonnaci Heap
 */
int FibonacciHeap::Delete_key(node* H1, int k)
{
    node* np = NULL;
    int t;
    t = Decrease_key(H1, k, -5000);
    if (!t)
        np = Extract_min(H);
    if (np != NULL)
        cout<<"Key Deleted"<<endl;
    else
        cout<<"Key not Deleted"<<endl;
    return 0;
}