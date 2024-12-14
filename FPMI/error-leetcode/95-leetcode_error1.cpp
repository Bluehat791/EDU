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

class SplayTree
{
    public:
        SplayTree()
        {
        }
 
        // RR(Y rotates to the right)
        TreeNode* RR_Rotate(TreeNode* k2)
        {
            TreeNode* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            return k1;
        }
 
        // LL(Y rotates to the left)
        TreeNode* LL_Rotate(TreeNode* k2)
        {
            TreeNode* k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            return k1;
        }
 
        // An implementation of top-down splay tree
        // TreeNode* Splay(int key, TreeNode* root)
        // {
        //     if (!root)
        //         return NULL;
        //     TreeNode header;
        //     /* header.rchild points to L tree;
        //     header.lchild points to R Tree */
        //     header.left = header.right = NULL;
        //     TreeNode* LeftTreeMax = &header;
        //     TreeNode* RightTreeMin = &header;
        //     while (1)
        //     {
        //         if (key < root->val)
        //         {
        //             if (!root->left)
        //                 break;
        //             if (key < root->left->val)
        //             {
        //                 root = RR_Rotate(root);
        //                 // only zig-zig mode need to rotate once,
        //                 if (!root->left)
        //                     break;
        //             }
        //             /* Link to R Tree */
        //             RightTreeMin->left = root;
        //             RightTreeMin = RightTreeMin->left;
        //             root = root->left;
        //             RightTreeMin->left = NULL;
        //         }
        //         else if (key > root->val)
        //         {
        //             if (!root->right)
        //                 break;
        //             if (key > root->right->val)
        //             {
        //                 root = LL_Rotate(root);
        //                 // only zag-zag mode need to rotate once,
        //                 if (!root->right)
        //                     break;
        //             }
        //             /* Link to L Tree */
        //             LeftTreeMax->right = root;
        //             LeftTreeMax = LeftTreeMax->right;
        //             root = root->right;
        //             LeftTreeMax->right = NULL;
        //         }
        //         else
        //             break;
        //     }
        //     /* assemble L Tree, Middle Tree and R tree */
        //     LeftTreeMax->right = root->left;
        //     RightTreeMin->left = root->right;
        //     root->left = header.right;
        //     root->right = header.left;
        //     return root;
        // }
 
        TreeNode* New_Node(int key)
        {
            TreeNode* p_node = new TreeNode;
            if (!p_node)
            {
                fprintf(stderr, "Out of memory!\n");
                exit(1);
            }
            p_node->val = key;
            p_node->left = p_node->right = NULL;
            return p_node;
        }
 
        TreeNode* Insert(int key, TreeNode* root)
        {
            static TreeNode* p_node = NULL;
            if (!p_node)
                p_node = New_Node(key);
            else
                p_node->val = key;
            if (!root)
            {
                root = p_node;
                p_node = NULL;
                return root;
            }
            //root = Splay(key, root);
            /* This is BST that, all keys <= root->key is in root->lchild, all keys >
            root->key is in root->rchild. */
            if (key < root->val)
            {
                p_node->left = root->left;
                p_node->right = root;
                root->left = NULL;
                root = p_node;
            }
            else if (key > root->val)
            {
                p_node->right = root->right;
                p_node->left = root;
                root->right = NULL;
                root = p_node;
            }
            else
                return root;
            p_node = NULL;
            return root;
        }
 
        TreeNode* Delete(int key, TreeNode* root)
        {
            TreeNode* temp;
            if (!root)
                return NULL;
            //root = Splay(key, root);
            if (key != root->val)
                return root;
            else
            {
                if (!root->left)
                {
                    temp = root;
                    root = root->right;
                }
                else
                {
                    temp = root;
                    /*Note: Since key == root->key,
                    so after Splay(key, root->lchild),
                    the tree we get will have no right child tree.*/
                    //root = Splay(key, root->left);
                    root->right = temp->right;
                }
                free(temp);
                return root;
            }
        }
 
        // TreeNode* Search(int key, TreeNode* root)
        // {
        //     return Splay(key, root);
        // }
 
        void InOrder(TreeNode* root)
        {
            if (root)
            {
                InOrder(root->left);
                cout<< "key: " <<root->val;
                if(root->left)
                    cout<< " | left child: "<< root->left->val;
                if(root->right)
                    cout << " | right child: " << root->right->val;
                cout<< "\n";
                InOrder(root->right);
            }
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
            SplayTree st;
            TreeNode* root = nullptr;
            for (size_t j = 0; j < nums[i].size(); j++)
            {
                root = st.Insert(nums[i][j],root);
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
        vector<TreeNode*> result = getAllTrees(comb);
        deleteDublicate(result);
        return result;
    }
};

int main() {
    
    Solution sol;
    vector<TreeNode*> tmp = sol.generateTrees(3);

    cout << "hello\n";
    return 0;
}