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

class binaryTree {

    TreeNode* root;
    TreeNode* left;
    TreeNode* right;

    TreeNode* insert(TreeNode* root,int key, int val, bool isLeft)
    {   
        if(root == nullptr)
            return new TreeNode(key);
        if(key>root->val)
            return insert(root->right,key,val,isLeft);
        else if(key>root->val)
            return insert(root->right,key,val,isLeft);
        else if(isLeft)
            return root->left= new TreeNode(val);
        else
            return root->right = new TreeNode(val);        
    }

public:
    void insert(int key, int val, bool isLeft){
        insert(root,key,val, isLeft);
    }

    void setRoot(int key){
        root = new TreeNode(key);
    }

    TreeNode* getRoot(){
        return root;
    }
};

class Solution {
    binaryTree btree;

    TreeNode* createSubTree(vector<int>& nums1,vector<int>& nums2)
    {   
        int root = nums1[0];       
        if(!nums2.empty()){
            TreeNode* leftchild = new TreeNode(nums1[2]?nums1[1]:nums2[1]);
            TreeNode* rightchild = new TreeNode(!nums1[2]?nums1[1]:nums2[1]);
            return new TreeNode(root,leftchild,rightchild);
        } else {
            TreeNode* child = new TreeNode(nums1[1]);
            if(nums1[2]){
                return new TreeNode(root,child,nullptr);
            } else {
                return new TreeNode(root,nullptr,child);
            }
        }
    }

    void merge(TreeNode* node1, TreeNode* node2)
    {
        if(node2->left->val == node1->val)
        {
            delete node2->left;
            node2->left = node1;
        } else if (node2->right->val == node1->val) {
            delete node2->right;
            node2->right = node1;
        } else if (node1->left->val == node2->val) {
            delete node1->left;
            node1->left = node2;
        } else if (node1->right->val == node2->val) {
            delete node1->right;
            node1->right = node2;
        }
    }
    
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        sort(descriptions.begin(),descriptions.end());
        vector<TreeNode*> tmp;
        for(int i = 0; i < descriptions.size()-2;i+=2)
        {
            tmp.push_back(createSubTree(descriptions[i],descriptions[i+1]));
        }

        return btree.getRoot();
    }
};


int main(){
    Solution sol;
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};

    TreeNode* result = sol.createBinaryTree(descriptions);

    cout << "Hello\n";
}
