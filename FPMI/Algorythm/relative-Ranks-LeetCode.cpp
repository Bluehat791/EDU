#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void heapify(vector<int>& score,int n, int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if (left<n&&score[left]>score[largest])
        {
            largest = left;
        }
        if (right<n&&score[right]>score[largest])
        {
            largest = right;
        }

        if(largest!=index)
        {
            swap(score[index],score[largest]);
            heapify(score,n,largest);
        }
        
    }

    void heapSort(vector<int>& score){
        for(int i = score.size()/2 -1;i>=0;i--)
            heapify(score,score.size()-1,i);

        for (int i = score.size()-1; i >=0; i--)
        {
            swap(score[0],score[i]);
            heapify(score,i,0);
        }
        
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        //heapSort(score);
        vector<string> result(score.size());
        // for (size_t i = 0; i < score.size(); i++)
        // {
        //     result[i] = to_string(score[i]);
        // }

        // result[0] = "Gold Medal";
        // result[1] = "Silver Medal";
        // result[2] = "Bronze Medal";

        for (size_t i = 0; i < score.size(); i++)
        {
            int largest = i;
            for (size_t j = 0; j < score.size(); j++)
            {
                if(score[j]>score[largest])
                    largest = j;
            }
            if(i==0){
                result[largest] = "Gold Medal";
                score[largest]=0;
                continue;
            }
            if(i==1){
                result[largest] = "Silver Medal";
                score[largest]=0;
                continue;
            }
            if(i==2) {
                result[largest] = "Bronze Medal";
                score[largest]=0;
                continue;
            } else 
            result[largest] = to_string(i+1);
            score[largest] = 0;
        }

        

        return result;
    }
};



int main(){
    Solution sol;
    vector<int> ivec = {5,4,3,2,1};
    vector<string> vec = sol.findRelativeRanks(ivec);
    for(const auto& m : vec)
        cout << m << " ";
    cout << '\n';
}