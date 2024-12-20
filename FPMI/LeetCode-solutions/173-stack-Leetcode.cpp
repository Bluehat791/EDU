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

class BSTIterator {
    stack<TreeNode*> result;
    void push_left(TreeNode* root)
    {   
        TreeNode* tmp = root;
        while(tmp!=nullptr)
        {
            result.push(tmp);
            tmp=tmp->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
        TreeNode* tmp = result.top();
        result.pop();
        push_left(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !result.empty();
    }
};

int main()
{
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);
    cout<< it.next() <<"\n";
    cout<< it.next() <<"\n";
    cout<< it.hasNext() <<"\n";
    cout<< it.next() <<"\n";
    cout<< it.hasNext()<<"\n";
    cout<< it.next() <<"\n";
    cout<< it.hasNext()<<"\n";
    cout<< it.next() <<"\n";
    cout<<"Hello\n";
}