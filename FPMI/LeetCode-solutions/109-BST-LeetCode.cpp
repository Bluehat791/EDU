#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void push_back(int key){
        if(next == nullptr)
            next = new ListNode(key);
        
        while (next!=nullptr)
        {
            
        }
        
    }
};


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),left(left), right(right) {}
};

class AVLTree {
    TreeNode* root;
    TreeNode* left;
    TreeNode* right;

    int height(TreeNode* node)
    {
        
        if(node == nullptr)
            return 0;
        
        return max(height(node->left),height(node->right)) + 1; 
    }

    int balanceFactor(TreeNode* node)
    {
        
        if(node == nullptr)
            return 0;
        
        return height(node->left) - height(node->right); 
    }

    TreeNode* insert(TreeNode* node,int key){
        if(node==nullptr)
            return new TreeNode(key);
        
        if(key > node->val)
            node->right = insert(node->right,key);
        else if(key > node->val) 
            node->left = insert(node->left,key);
        else 
            return node;

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->val)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->val)
        {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVLTree()
        : root(nullptr),left(nullptr),right(nullptr)
    {}

    TreeNode* rightRotate(TreeNode* node){
        TreeNode* x = node->left;
        TreeNode* T2 = x->right;

        x->right = node;
        node->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* node){
        TreeNode* x = node->right;
        TreeNode* T2 = x->left;

        x->left = node;
        node->right = T2;

        return x;
    }

    void insert(int key) {
        root = insert(root,key);
    }

    TreeNode* getRoot(){
        return root;
    }
};


class Solution {
    AVLTree avl;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        for(ListNode* tmp = head;tmp!=nullptr;tmp=tmp->next)
            avl.insert(tmp->val);
        
        return avl.getRoot();
    }
};

int main() {
    Solution sol;

    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);;
    node1->left = node2;
    node1->right = nullptr;
    TreeNode* node3 = new TreeNode(2);
    node2->right = node3;
    TreeNode* node4 = nullptr;
    node2->left = node4;
    

    vector<int> tmp = sol.findMode(node1);

    cout << "hello\n";
}