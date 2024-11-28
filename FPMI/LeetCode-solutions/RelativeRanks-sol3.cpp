#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    int getIndex(vector<int>& score, int k){
        int index;
        auto it = find(score.begin(), score.end(), k);

        if(it != score.end()){
            index = it - score.begin();
            return index;
        }
        return *it;
    }

public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int n = score.size();
        priority_queue<int> pq;
        int rank =1;

        for (size_t i = 0; i < n; i++)
        {
            pq.push(score[i]);
        }

        vector<int> classification(n);

        while (!pq.empty())
        {
            int temp = pq.top();
            pq.pop();
            int idx = getIndex(score, temp);
            classification[idx] = rank;
            rank++;
        }
        
        vector<string> result(n);

        for(int i=0 ; i<n ; i++){
            if(classification[i] == 1){
                result[i] = "Gold Medal";
            }
            else if(classification[i] == 2){
                result[i] = "Silver Medal";
            }
            else if(classification[i] == 3){
                result[i] = "Bronze Medal";
            }
            else{
                result[i] = to_string(classification[i]);
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> ivec = {10,3,8,9,4};
    vector<string> vec = sol.findRelativeRanks(ivec);
    for(const auto& m : vec)
        cout << m << " ";
    cout << '\n';
}