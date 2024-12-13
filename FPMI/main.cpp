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

    TreeNode* insert(TreeNode* node,int key){
        if(node==nullptr)
            return new TreeNode(key);
        
        if(key > node->val)
            node->right = insert(node->right,key);
        else if(key > node->val) 
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

    void insert(int key) {
        root = insert(root,key);
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

    vector<AVLTree> getAllTrees(vector<vector<int>>& nums){
        vector<AVLTree> tmp;
        for (size_t i = 0; i < nums.size(); i++)
        {
            tmp.push_back(AVLTree());
            tmp[i].insert(nums[i][0]);
            tmp[i].insert(nums[i][1]);
            tmp[i].insert(nums[i][2]);
            tmp[i].insert(nums[i][3]);
        }
        return tmp;
    } 

    bool equalTrees(TreeNode* nums1, TreeNode* nums2)
    {   

        bool equal = true;
        if(nums1->val==nums2->val)
        {
            if(nums1->left != NULL && nums2->right != NULL)
            {
                equal = equalTrees(nums1->left, nums2->left);
                equal = equalTrees(nums1->right, nums2->right);
            }
        } else {
            equal = false;
        }
        return equal;
    }

    void deleteDublicate(vector<TreeNode*>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i+1; j < nums.size()-1; j++)
            {
                if(equalTrees(nums[i],nums[j]))
                    nums.erase(nums.begin()+j);
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> tmp1;
        for (size_t i = 1; i < n+1; i++)
        {
            tmp1.push_back(i);
        }
        getAllCombinations(tmp1,0);
        vector<AVLTree> tmp2 = getAllTrees(comb);
        return vector<TreeNode*>(7);
    }
};

int main() {
    
    Solution sol;
    vector<TreeNode*> tmp = sol.generateTrees(4);

    cout << "hello\n";
    return 0;
}