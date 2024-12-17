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
    int rangeSumBST(TreeNode* root, int low, int high) {
        tree_assign(root);
        sort(result.begin(),result.end());
        int low_index = 0;
        while (result[low_index]<low)
            low_index++;
        
        int high_index = result.size()-1;
        while (result[high_index]>high)
            high_index--;

        int resSum = 0;
        for (size_t i = low_index; i <= high_index; i++)
        {
            resSum +=result[i];
        }
        
        return resSum;
    }
};

int main() {
    Solution sol;    

    TreeNode* tmp = new TreeNode(10);

    cout << sol.rangeSumBST(tmp,6,10)  <<" hello\n";
    return 0;
}