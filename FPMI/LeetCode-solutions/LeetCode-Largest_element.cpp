#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class KthLargest {
    int kth_count;
    priority_queue<int,vector<int>,greater<int>> result;
public:
    KthLargest(int k, vector<int>& nums)
    : kth_count(k) {
        for (size_t i = 0; i < nums.size(); i++)
        {
            result.push(nums[i]);
            if (result.size()>kth_count)
            {
                result.pop();
            }
            
        }
        
    }
    
    int add(int val) {
        result.push(val);
        if (result.size()>kth_count)
        {
            result.pop();
        }
        
        return result.top();
    }
};



int main(){
    vector<int> tmp = {4,5,8,2};
    KthLargest* obj = new KthLargest(3,tmp);
    int para_1 = obj->add(3);
    int para_2 = obj->add(5);
    int para_3 = obj->add(10);
    int para_4 = obj->add(9);
    int para_5 = obj->add(4);

    cout << para_1 << " ";
    cout << para_2 << " ";
    cout << para_3 << " ";
    cout << para_4 << " ";
    cout << para_5 << " ";
    cout << '\n';

    delete obj;
}