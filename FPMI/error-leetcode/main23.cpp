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
    void recoverTree(TreeNode* root) {  

        
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