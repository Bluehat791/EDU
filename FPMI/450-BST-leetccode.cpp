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
    TreeNode* tmp = nullptr;
    void find_node(TreeNode* root, int& key)
    {
        if(!root) return;

        if(root->val == key)
        {
            tmp = root;
        }
        else{
            find_node(root->left,key);
            if(!tmp)
                find_node(root->right,key);
        }

    }

    void deleteHelper(TreeNode*& root, TreeNode* tmp)
    {
        if(!root) return;
        if(!tmp) return;
        if(root==tmp)
        {
            if(!root->left && !root->right)
            {
                root=nullptr;
                return;
            } else if(root->right && !root->left)
            {
                root = root->right;
                return;
            } else if (!root->right && root->left)
            {
                root= root->left;
                return;
            } else
            {
                tmp=tmp->right;
                while(tmp->left)
                {
                    tmp=tmp->left;
                }
                swap(tmp->val,root->val);
                TreeNode* current2 = root;
                if(current2->right == tmp)
                    current2->right = tmp->right;
                else    
                {
                    current2 = current2->right;
                    while (current2->left!=tmp)
                    {
                        current2=current2->left;
                    }
                    current2->left = tmp->right;
                }
                delete tmp;
                return;
            }
        }
        if(root->left==tmp)
            if(!tmp->left && !tmp->right)
            {
                delete tmp;
                root->left = nullptr;
            }
            else if(tmp->right && !tmp->left )
            {
                root->left = tmp->right;
                delete tmp;
                return;
            } else if(!tmp->right && tmp->left)
            {
                root->left = tmp->left;
                delete tmp;
                return;
            }
            else
            {
                TreeNode* current = tmp;
                current = current->right;
                while (current->left)
                {
                    current = current->left;
                }
                swap(current->val,tmp->val);
                TreeNode* current2 = tmp;
                if(current2->right == current)
                    current2->right = current->right;
                else    
                {
                    current2 = current2->right;
                    while (current2->left!=current)
                    {
                        current2=current2->left;
                    }
                    current2->left = current->right;
                }
                
                delete current;
                return;
            }
        else if(root->right==tmp)
            if(!tmp->left && !tmp->right)
            {
                delete tmp;
                root->right = nullptr;
            }
            else if(tmp->right && !tmp->left )
            {
                root->right = tmp->right;
                delete tmp;
                return;
            } else if(!tmp->right && tmp->left)
            {
                root->right = tmp->left;
                delete tmp;
                return;
            }
            else {
                TreeNode* current = tmp;
                current = current->left;
                while (current->right)
                {
                    current = current->right;
                }
                swap(current->val,tmp->val);
                TreeNode* current2 = tmp;
                if(current2->left==current)
                    current2->left = current->left;
                else
                {
                    current2 = current2->left;
                    while (current2->right!=current)
                    {
                        current2 = current2->right;
                    }
                    current2->right = current->left;
                }
                delete current;
                return;
            }

        deleteHelper(root->left,tmp);
        deleteHelper(root->right,tmp);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        find_node(root,key);
        deleteHelper(root,tmp);
        return root;
    }
};


int main()
{
    TreeNode* root = new TreeNode(4);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(5);
    Solution sol;

    TreeNode* tmp = sol.deleteNode(root,7);
    cout << "hello\n";
}