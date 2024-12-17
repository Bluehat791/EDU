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
    void tree_assign(TreeNode* root){
        if(root!=nullptr){
            result.push_back(root->val);

            tree_assign(root->left);
            tree_assign(root->right);
        } 
    }

    int minDiffHelper(TreeNode* root)
    {
        tree_assign(root);
        int minDiff = INT_MAX;
        for (size_t i = 0; i < result.size(); i++)
        {
            for (size_t j = 1; j < result.size(); j++)
            {   
                if(i==j)
                    continue;
                int tmpDiff = result[i]>result[j]?result[i]-result[j]:result[j]-result[i];
                if(tmpDiff<minDiff)
                    minDiff = tmpDiff;
            }
        }
        return minDiff;
    }
public:
    int minDiffInBST(TreeNode* root) {
        return minDiffHelper(root);
    }
};

int main() {
    
    Solution sol;
    TreeNode* root = new TreeNode(4);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(6);
    root->left = left;
    root->right = right;
    
    TreeNode* leftleft = new TreeNode(1);
    TreeNode* leftright = new TreeNode(3);
    left->left = leftleft;
    left->right = leftright;

    cout << sol.minDiffInBST(root) <<" hello\n";
    return 0;
}