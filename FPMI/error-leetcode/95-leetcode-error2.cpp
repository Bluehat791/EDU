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

    // void insert(int key) {
    //     root = insert(root,key);
    // }

    TreeNode* insert(TreeNode* node,int key){
        if(node==nullptr)
            return new TreeNode(key);
        
        if(key > node->val)
            node->right = insert(node->right,key);
        else if(key < node->val) 
            node->left = insert(node->left,key);
        else 
            return node;

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

        for (size_t i = 0; i < nums.size(); i++)
        {
            if(isDuplicate[i])
                nums.erase(nums.begin()+i);
        }
        

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     for (size_t j = i+1; j < nums.size()-1; j++)
        //     {
        //         if(equalTrees(nums[i],nums[j]))
        //             nums.erase(nums.begin()+j);
        //     }
        // }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> tmp1;
        for (size_t i = 1; i < n+1; i++)
        {
            tmp1.push_back(i);
        }
        getAllCombinations(tmp1,0);
        vector<TreeNode*> tmp2 = getAllTrees(comb);
        deleteDublicate(tmp2);
        deleteDublicate(tmp2);
        vector<bool> indexD = indexDublicat(tmp2);
        return tmp2;
    }
};

int main() {
    
    Solution sol;
    vector<TreeNode*> tmp = sol.generateTrees(4);

    cout << "hello\n";
    return 0;
}