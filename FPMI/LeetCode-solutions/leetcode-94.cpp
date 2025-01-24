#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    vector<int> result;
    stack<int> st;
    
    void helper(TreeNode *root)
    {
        if(root==nullptr)
            return;
        st.push(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(st.top());
            st.pop();
        }
        else
        {
            helper(root->left);
            result.push_back(st.top());
            st.pop();
            helper(root->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode *root)
    {   
        helper(root);
        return result;
    }
};

int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.inorderTraversal(root);

    cout << "loal\n";
}