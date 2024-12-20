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

class Codec {
    string result ="";
    string tree_assign(TreeNode* root)
    {
        if(!root) return "#";
        return to_string(root->val) + tree_assign(root->left) + tree_assign(root->right);
    }
    TreeNode* createNode(TreeNode*& node, char key)
    {
        if(key=='#') return nullptr;

        node = new TreeNode(key-'0');
        return node;
    }

    TreeNode* desHelper(TreeNode*& root,string& data,int index)
    {   
        if(index>=data.size() || data=="") return nullptr;

        string tmp="";
        while(index<data.size() && data[index]!=',') tmp+=data[index++];
        index++;
        if(tmp=="#") return nullptr;
        root=new TreeNode(stoi(tmp));
        root->left=desHelper(root->left,data,index);
        root->right=desHelper(root->left,data,index);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return tree_assign(root);;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        TreeNode* tmp=nullptr;
        int index=0;
        return desHelper(tmp,data,index);
    }
};


int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Codec cd;

    cout << cd.serialize(root) << "\n";
    cout << cd.deserialize(cd.serialize(root)) << "\n"; 
    cout<<"Hello\n";
}