 #include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //priority_queue<TreeNode> result;
    //vector<pair<int,int>> tmp;

    int getMax_index(vector<int>& nums)
    {
        int mx_index= 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[mx_index]<nums[i])
                mx_index=i;
        }
        return mx_index;
    }


public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;

        int mx_i = getMax_index(nums);
        TreeNode* max_node = new TreeNode(nums[mx_i]);


        vector<int> left_nums(nums.begin(),nums.begin()+mx_i);
        max_node->left = constructMaximumBinaryTree(left_nums);

        // if(mx_i==0)
        //     mx_i=1;

        vector<int> right_nums(nums.begin()+mx_i+1,nums.end());
        max_node->right = constructMaximumBinaryTree(right_nums);

        return max_node;
    }
};

int main(){
    Solution sol;
    vector<int> tmp = {3,2,1};
    TreeNode* result = sol.constructMaximumBinaryTree(tmp);

    cout << "fsdfsfs";
}