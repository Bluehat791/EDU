#include<bits/stdc++.h>
using namespace std;

class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(int size) : size_(size), tree_(size+1,0)
    {}

    void update(int index, int delta) {
        while (index<=size_)
        {
            tree_[index]+=delta;
            index+= index & -index;
        }
    }

    int query(int index){
        int sum = 0;
        while (index>0)
        {
            sum+=tree_[index];
            index-= index & -index;
        }
        return sum;
    }

private:
    int size_;
    vector<int> tree_;
};

class Solution {
    int result = 0;
    vector<int> nums;
public:
    int createSortedArray(vector<int>& instructions) {
        int maxElement = *max_element(instructions.begin(),instructions.end());
        BinaryIndexedTree tree(maxElement);
        const int mod = 1e9 +7;
        int cost = 0;

        for (int i = 0; i < instructions.size(); ++i)
        {
            int num = instructions[i];

            int currentCost = min(tree.query(num-1),i - tree.query(num));

            cost = (cost + currentCost) % mod;
            tree.update(num,1);
        }
        return cost;
    }
};

int main()
{

}