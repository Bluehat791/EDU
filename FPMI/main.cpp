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

class AVLTree {
    TreeNode* root;

    int height(TreeNode* node)
    {
        
        if(node == nullptr)
            return 0;
        
        return max(height(node->left),height(node->right)) + 1; 
    }

    int balanceFactor(TreeNode* node)
    {
        
        if(node == nullptr)
            return 0;
        
        return height(node->left) - height(node->right); 
    }

public:
    AVLTree()
        : root(nullptr)
    {}

    TreeNode* rightRotate(TreeNode* node){
        TreeNode* x = node->left;
        TreeNode* T2 = x->right;

        x->right = node;
        node->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* node){
        TreeNode* x = node->right;
        TreeNode* T2 = x->left;

        x->left = node;
        node->right = T2;

        return x;
    }

    TreeNode* insert(TreeNode* node,int key){
        if(node==nullptr)
            return new TreeNode(key);
        
        if(key > node->val)
            node->right = insert(node->right,key);
        else if(key < node->val) 
            node->left = insert(node->left,key);
        else 
            return node;

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->val)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->val)
        {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


    TreeNode* getRoot(){
        return root;
    }
};


class Solution {

    vector<vector<int>> comb;

    void getAllCombinations(vector<int> &nums, int startIndex) {
        if (startIndex == nums.size()) {
            vector<int> tmp;
            for (int i = 0; i < nums.size(); i++) {
               tmp.push_back(nums[i]);
            }
            comb.push_back(tmp);
            return;
        }


        for (int i = startIndex; i < nums.size(); i++) {
            swap(nums[startIndex], nums[i]);
            getAllCombinations(nums, startIndex + 1);
            swap(nums[startIndex], nums[i]); 
        }
    }

    vector<TreeNode*> getAllTrees(vector<vector<int>>& nums){
        vector<TreeNode*> tmp_ptr;
        for (size_t i = 0; i < nums.size(); i++)
        {   
            AVLTree avl;
            TreeNode* root = nullptr;
            for (size_t j = 0; j < nums[i].size(); j++)
            {
                root = avl.insert(root,nums[i][j]);
            }
            tmp_ptr.push_back(root);
        }
        return tmp_ptr;
    } 

    bool equalTrees(TreeNode* nums1, TreeNode* nums2)
    {   
        
        
        bool equal = true;
        if(nums1->val==nums2->val)
        {
            if(nums1->left != nullptr && nums2->left != nullptr)
            {
                equal = equalTrees(nums1->left, nums2->left);
            }
            if(nums1->right != nullptr && nums2->right != nullptr && equal)
            {
                equal = equalTrees(nums1->right, nums2->right);
            }
                
        } else {
            equal = false;
        }
        return equal;
    }

    vector<bool> indexDublicat(vector<TreeNode*>& nums)
    {
        vector<bool> isDuplicate(nums.size()); 
        for (size_t i = 0; i < nums.size(); ++i) {
            isDuplicate[i] = false; 
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!isDuplicate[i]) {
                for (size_t j = 0; j < nums.size(); ++j) {
                    if (equalTrees(nums[i],nums[j])&&j!=i) { 
                        isDuplicate[j] = true; 
                    }
                }
            }
        }
        return isDuplicate;
    }

    void deleteDublicate(vector<TreeNode*>& nums)
    {
        vector<AVLTree> result;
        bool isDuplicate[nums.size()]; 
        for (size_t i = 0; i < nums.size(); ++i) {
            isDuplicate[i] = false; 
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!isDuplicate[i]) {
                for (size_t j = i + 1; j < nums.size(); ++j) {
                    if (equalTrees(nums[i],nums[j])) { 
                        isDuplicate[j] = true; 
                    }
                }
            }
        }

        for (size_t i = 0,tmp = 0; i < nums.size()+tmp; i++)
        {
            if(isDuplicate[i]){
                nums.erase(nums.begin()+i-tmp);
                tmp++;
            }
        }
    }

    AVLTree original;
public:

    int numOfWays(vector<int>& nums) {

        getAllCombinations(nums,0);
        // vector<TreeNode*> tmp2 = getAllTrees(comb);
        return tmp2.size();
    }
};

int main() {
    
    Solution sol;
    vector<int> tmp = {3,4,5,1,2};
    int tmp2 = sol.numOfWays(tmp);

    cout << tmp2 << "hello\n";
    return 0;
}