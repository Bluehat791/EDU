#include<algorithm>
#include<iostream>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left;
}

Node* splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
    {
        return root;
    }

    if (root->key > key)
    {
        if (root->left == nullptr)
        {
            return root;
        }
        if (root->left->key > key)
        {
            root->left->left = splay(root->left->left,key);
            root = rightRotate(root);
        } 
        else if (root->left->key < key){
            root->left->right = splay(root->left->right, key);
            if (root->left->right!=nullptr)
            {
                root->left = leftRotate(root->left);
            }
            return (root->left = nullptr)?root:rightRotate(root);
        }
        else {
            if (root->right == nullptr)
            {
                return root;
            }
            if (root->right->key > key)
            {
                root->right->left = splay(root->right->left,key);
                if (root->right->left!=nullptr)
                {
                    root->right = rightRotate(root->right);
                }
                
            }
            else if (root->right->key < key)
            {
                root->right->right = splay(root->right->right,key);
                root = leftRotate(root);
            }
            return (root->right = nullptr)?root : leftRotate(root);
        }
        
        
    }
    
    
}
