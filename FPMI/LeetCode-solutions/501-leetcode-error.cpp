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
public:
    vector<int> ans;
    int maxi = 0, freq = 1, prev = -1e6;
    void helper(TreeNode* root){
        if(root==nullptr)
        {
            return;
        }
        helper(root -> left);
        if(prev == -1e6)
        {
            prev = root -> val;
        }
        else if(root -> val != prev)
        {
            if(freq > maxi)
            {
                maxi = freq;
                ans = {prev};
            }
            else if(freq == maxi)
            {
                ans.push_back(prev);
            }
            freq = 1;
            prev = root -> val;
        }
        else
            freq++;
        helper(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        if(freq > maxi)
        {
            ans = {prev};
        }
        else if(freq == maxi)
        {
            ans.push_back(prev);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);;
    node1->left = node2;
    node1->right = nullptr;
    TreeNode* node3 = new TreeNode(2);
    node2->right = node3;
    TreeNode* node4 = nullptr;
    node2->left = node4;
    

    vector<int> tmp = sol.findMode(node1);

    cout << "hello\n";
}