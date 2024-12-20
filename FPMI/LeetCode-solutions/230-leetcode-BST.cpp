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
    size_t index;
    vector<TreeNode*> result;
    bool first_flag = false;
    void tree_assign(TreeNode* node)
    {
        if(!node && !first_flag)
        {
            result.push_back(new TreeNode(INT_MIN));
            first_flag = true;
            return;
        } 
        if(!node) return;

        tree_assign(node->left);
        result.push_back(node);
        tree_assign(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        tree_assign(root);
        index = 0;
    }
    
    int next() {
        return result[++index]->val;
    }
    
    bool hasNext() {
        return index<result.size()-1;
    }

    int& operator[](int index)
    {
        return result[index]->val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       BSTIterator it(root);
       return it[k]; 
    }
};

int main()
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    Solution sol;
    
    cout << sol.kthSmallest(root,1) << "\n"; 
    cout<<"Hello\n";
}