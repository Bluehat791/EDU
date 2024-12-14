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

enum CONDITION{
    ROOT,
    LEFT,
    RIGHT
};

class Solution {
    vector<TreeNode*> result;

    void tree_assign(TreeNode* root){
        if(root!=nullptr){
            if(root!=nullptr)
                result.push_back(root);
            else
                result.push_back(nullptr);

            tree_assign(root->left);
            tree_assign(root->right);
        } 
    }

    bool isValidBSTHelper(vector<TreeNode*> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {   
            bool valid = true;
            for (int x = i*2+1,y = i*2+2; ; x=x*2+1,y=y*2+2)
            {
                if(x>=nums.size()||nums[x]==nullptr)
                    break;
                valid = nums[i];
                if(y>=nums.size()||nums[y]==nullptr)
                    break;

            }
            
        }
        
    }

public:
    bool isValidBST(TreeNode* root) {
        tree_assign(root);
        return true;
    }
};


int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(2);
    root->left = left;
    //root->right = right;
    
    cout << sol.isValidBST(root) << " hello\n";
    return 0;
}