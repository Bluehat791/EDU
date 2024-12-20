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
    vector<TreeNode*> one_depth;
    vector<TreeNode*> two_depth;

    void depth(TreeNode* root, int key,vector<TreeNode*>& depth_v)
    {
        if(!root) return;

        if(root->val == key)
        {
            depth_v.push_back(root);
            return;
        }

        depth_v.push_back(root);
        if(key<root->val)   
            depth(root->left,key,depth_v);
        else    
            depth(root->right,key,depth_v);
    }

    TreeNode* LCA(vector<TreeNode*>& first,vector<TreeNode*>& second)
    {
        int small_sz = first.size()<second.size()?first.size():second.size();

        for (int i = small_sz-1; i > -1; i--)
        {
            if (first[i]==second[i])
            {
                return first[i];
            }
            
        }
        return first[0];
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        depth(root,p->val,one_depth);
        depth(root,q->val,two_depth);
        return LCA(one_depth,two_depth);
    }
};

int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;
    TreeNode* one = new TreeNode(2);
    TreeNode* two = new TreeNode(8);
    cout << sol.lowestCommonAncestor(root,one,two)->val << "\n";
    cout<<"Hello\n";
}