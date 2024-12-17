#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),left(left), right(right) {}
};

class Tree {
    TreeNode* root;

    TreeNode* insert(TreeNode* node,int key){
        if(node==nullptr)
            return new TreeNode(key);
        
        if(key > node->val)
            node->right = insert(node->right,key);
        else if(key < node->val) 
            node->left = insert(node->left,key);
        else 
            return node;

        return node;
    }

public:
    Tree()
        : root(nullptr)
    {}

    void insert(int key) {
        root = insert(root,key);
    }

    TreeNode* getRoot(){
        return root;
    }
};

class Solution {
    vector<int> result;
    Tree tree;
    void tree_assign(TreeNode* root){
        if(root!=nullptr){
            result.push_back(root->val);

            tree_assign(root->left);
            tree_assign(root->right);
        } 
    }
    TreeNode* helper(TreeNode* node)
    {
        tree_assign(node);
        sort(result.rbegin(),result.rend());
        for (size_t i = 0; result.size()>0; result.pop_back())
        {
            tree.insert(result[result.size()-1]);
        }
        return tree.getRoot();
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root);
    }
};

int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(3);
    TreeNode* right = new TreeNode(6);
    root->left = left;
    root->right = right;
    
    TreeNode* leftleft = new TreeNode(2);
    TreeNode* leftright = new TreeNode(4);
    left->left = leftleft;
    left->right = leftright;
    //sol.increasingBST(root);
    TreeNode* tmp =  sol.increasingBST(root);
    cout  <<" hello\n";
    return 0;
}