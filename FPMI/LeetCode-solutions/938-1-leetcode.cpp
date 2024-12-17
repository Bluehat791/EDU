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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int tmp = (low<=root->val && high >=root->val)?root->val:0;

        int left = rangeSumBST(root->left,low,high);
        int right = rangeSumBST(root->right,low,high);
        return tmp + left + right;
    }
};

int main() {
    Solution sol;    

    TreeNode* root = new TreeNode(10);
    TreeNode* left = new TreeNode(5);
    TreeNode* right = new TreeNode(15);
    root->left = left;
    root->right = right;
    
    TreeNode* leftleft = new TreeNode(3);
    TreeNode* leftright = new TreeNode(7);
    left->left = leftleft;
    left->right = leftright;

    TreeNode* rightright = new TreeNode(18);
    right->right = rightright;

    cout << sol.rangeSumBST(root,7,15)  <<" hello\n";
    return 0;
}