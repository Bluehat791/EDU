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
    int find_count;
    bool found = false;
    void PUSH(vector<int>& nums,int count)
    {   
        nums.push_back(count);
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            if(nums[i]+count == find_count)
            {
                found = true;
                return;
            }
        }
        
    }
    void tree_assign(TreeNode* root){
        if(root!=nullptr && !found){
            PUSH(result,root->val);

            tree_assign(root->left);
            tree_assign(root->right);
        } 
    }
public:
    bool findTarget(TreeNode* root, int k) {
        find_count = k;
        tree_assign(root);
        return found;
    }
};

int main() {
    Solution sol;

    TreeNode* node1 = new TreeNode(4);
    TreeNode* Lnode1 = new TreeNode(2);
    TreeNode* Rnode1 = new TreeNode(6);
    node1->left = Lnode1;
    node1->right = Rnode1;

    TreeNode* Lnode2 = new TreeNode(1);
    TreeNode* Rnode2 = new TreeNode(3);
    Lnode1->left = Lnode2;
    Lnode1->right = Rnode2;

    //int tmp = sol.getMinimumDifference(node1);

    cout << "hello\n";
}