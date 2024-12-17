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
    vector<int> result;
    void increaseKey(TreeNode* node,int key,int count){
        if(!node) return;

        if(node->val == key)
            node->val+= count;
        
        if(node->val < key)
            increaseKey(node->right,key,count);
        else
            increaseKey(node->left,key,count);
    }
    void tree_assign(TreeNode* root){
        if(root!=nullptr){
            result.push_back(root->val);

            tree_assign(root->left);
            tree_assign(root->right);
        } 
    }

    
public:
    TreeNode* bstToGst(TreeNode* root) {
        tree_assign(root);
        sort(result.begin(),result.end());
        for (int i = result.size()-1,count = 0; i > -1; count+=result[i--])
        {   
            increaseKey(root,result[i],count);
        }
        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    sol.bstToGst(root);
    cout << "Hello\n";
}