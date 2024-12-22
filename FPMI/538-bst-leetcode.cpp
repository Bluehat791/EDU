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
    int tmp = INT_MIN;
    TreeNode* max_element = nullptr;
    bool flag = false;
    void updateTree(TreeNode* root)
    {
        if(!root) return;
        
        if(root==max_element)
        {
            tmp=root->val;
            //return;
        }
        updateTree(root->right);
        if(tmp!=INT_MIN && flag)
        {
            root->val+=tmp;
            tmp = root->val;
        }
        flag=true;
        updateTree(root->left);
    }

    void find_max(TreeNode* root)
    {   
        if(!root) return;
        while (root->right)
        {
            root=root->right;
        }
        max_element = root;
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        find_max(root);
        updateTree(root);
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);

    Solution sol;

    TreeNode* tmp = sol.convertBST(root);
    cout << "hello\n";
}