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
    
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int N = 100001;
        bitset<N> seen = 0;
        int root = -1;
        int parent[N] = {0};
        TreeNode* node[N] = {nullptr};

        for(auto& d: descriptions){
            int tmp_p = d[0], tmp_c = d[1], l = d[2];
            if (!seen[tmp_p])
            {
                node[tmp_p] = new TreeNode(tmp_p);
                seen[tmp_p] = 1;
                if(parent[tmp_p] == 0)
                    root =tmp_p;
            }
            if(!seen[tmp_c]) {
                node[tmp_c] = new TreeNode(tmp_c);
                seen[tmp_c]=1;
            }
            parent[tmp_c] = tmp_p;
            if(l)
                node[tmp_p]->left = node[tmp_c];
            else
                node[tmp_p]->right = node[tmp_c];
        }
        while(parent[root] != 0)
            root = parent[root];
        return node[root];
    }
};


int main(){
    Solution sol;
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};

    TreeNode* result = sol.createBinaryTree(descriptions);

    cout << "Hello\n";
}
