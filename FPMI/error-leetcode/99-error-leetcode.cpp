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
    void find_error(TreeNode* node, long min,long max)
    {   
        if(two_er.size()==2) return;
        if(!node) return;

        if(node->val>max || node->val<min)
            two_er.push_back(node);
        
        find_error(node->left,min,node->val);
        find_error(node->right,node->val,max);
    }

    bool first_helper(TreeNode* root)
    {   
        if(root->left&&root->right&&(root->left->val>root->val && root->right->val<root->val))
        {
            two_er.push_back(root->right);
            two_er.push_back(root->left);
            return true;
        }
        
        if(!find_min(root,root->right,root))
            return find_max(root,root->left,root);
        else
            return true;

        return false;
    }

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

    bool find_max(TreeNode* root,TreeNode* node,TreeNode*& max)
    {
        if(!root) return false;
        if(!node) return false;

        if(node->val>max->val)
            max = node;
        
        find_max(root,node->right,max);
        find_max(root,node->left,max);

        if(root->left == node && root->val!=max->val)
        {
            swap(root->val,max->val);
            return true;
        }
        return false;
    }
    

public:
    void recoverTree(TreeNode* root) {  
        if(!first_helper(root)){
            find_error(root,LONG_MIN,LONG_MAX);
        }
        else
        {   if(two_er.size()==2)
                swap(two_er[0]->val,two_er[1]->val);
            return;
        }   
        if(two_er.size()==2)
            swap(two_er[0]->val,two_er[1]->val);
    }
};

int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(1);
    //root->right->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(2);

    sol.recoverTree(root);
    cout << "hello\n";
    return 0;
}