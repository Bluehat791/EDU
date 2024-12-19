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

class Solution {
    vector<TreeNode*> two_er;
    bool find_min(TreeNode* root,TreeNode* node,TreeNode*& min)
    {
        if(!root) return false;
        if(!node) return false;

        if(node->val<min->val)
            min = node;
        
        find_min(root,node->right,min);
        find_min(root,node->left,min);

        if(root->right == node && root->val!=min->val)
        {
            swap(root->val,min->val);
            return true;
        }
        return false;
    }

    bool find_max(TreeNode* root,TreeNode* node,TreeNode* max)
    {
        if(!root) return false;
        if(!node) return false;

        if(node->val>max->val)
            max = node;
        
        find_min(root,node->right,max);
        find_min(root,node->left,max);

        if(root->left == node && root->val!=max->val)
        {
            swap(root->val,max->val);
            return true;
        }
        return false;
    }

public:
    void recoverTree(TreeNode* root) {  
        TreeNode* tmp = root;
        if(!find_min(root,root->right,tmp))
            find_max(root,root->left,tmp);
        
    }
};

int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(3);
    //root->right->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(1);

    sol.recoverTree(root);
    cout << "hello\n";
    return 0;
}