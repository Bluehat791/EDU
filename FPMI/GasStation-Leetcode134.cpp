#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (size_t i = 0; i < gas.size(); i++)
        {
            int gas_count = gas[i];
            int x = 0;
            size_t j = i,w=i+1;
            for (;x < cost.size()-1; j++,x++,w++)
            {   
                if(j==cost.size())
                    j=0;
                if(w==cost.size())
                    w=0;

                gas_count-=cost[j];
                if(gas_count<=0)
                    break;

                gas_count+=gas[w];
            }

                if(j==cost.size())
                    j=0;
                if(w==cost.size())
                    w=0;

            if(x==cost.size()-1 &&  (gas_count - cost[j])>=0 )
                return i;
        }
        return -1;
    }
};


int main()
{
    Solution sol;
    vector<int> gas = {4,5,3,1,4};
    vector<int> cost = {5,4,3,4,2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;
}