#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> deq(nums.begin(),nums.end());
        for (size_t i = 0; i < k; i++)
        {   
            deq.push_front(deq.back());
            deq.pop_back();
        }   

        nums.clear();
        
        for (const auto&  i : deq)
        {
            nums.push_back(i);
        }
        
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = {-1,-100,3,99};
    sol.rotate(tmp,2);
    for(auto const& i : tmp)
    {
        cout << i << " ";
    }
    cout << endl;
}
