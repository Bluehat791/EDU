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

    bool isValidHelper(TreeNode* node, long min, long max)
    {
        if(!node) return true;

        if(!(node->val>min && node->val<min)) return false;

        return isValidHelper(node->left,min,node->val) && isValidHelper(node->right,node->val,max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root,LONG_MIN,LONG_MAX);
    }
};


int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(4);
    root->left = left;
    root->right = right;
    
    //TreeNode* node = new TreeNode(32, TreeNode(26,TreeNode(19,nullptr, TreeNode(27)), nullptr))

    cout << sol.isValidBST(root) << " hello\n";
    return 0;
}