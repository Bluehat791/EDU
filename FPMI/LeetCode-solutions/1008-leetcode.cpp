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

class AVLTree {
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
    AVLTree()
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
    AVLTree avl;
    void tree_assign(vector<int>& nums){
        for (size_t i = 0; i < nums.size(); i++)
        {
            avl.insert(nums[i]);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        tree_assign(preorder);
        return avl.getRoot();
    }
};

int main() {
    Solution sol;    

    vector<int> t

    //cout << sol.rangeSumBST(root,7,15)  <<" hello\n";
    return 0;
}