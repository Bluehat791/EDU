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

class BSTIterator {
    TreeNode* ptr=nullptr;
    TreeNode* root_r=nullptr;

public:
    BSTIterator(TreeNode* root) {
        root_r = root;
        while(root->left)
            root=root->left;
        ptr=root;
    }
    
    int next() {
        TreeNode* tmp =root_r;
        while(tmp->left);
    }
    
    bool hasNext() {
        return (ptr->right);
    }
};

int main()
{

}