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
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        tree_assign(root1);
        tree_assign(root2);
        sort(result.begin(),result.end());
        return result;
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(4);

    //sol.getAllElements(root);
    cout << "Hello\n";
}