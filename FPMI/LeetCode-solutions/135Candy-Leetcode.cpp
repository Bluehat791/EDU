#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy_count(ratings.size(),1);
        for (size_t i = 1; i < ratings.size(); i++)
        {
            if (ratings[i]>ratings[i-1])
            {
                candy_count[i]=candy_count[i-1]+1;
            }
        }

        for (int i = ratings.size()-2; i >= 0; i--)
        {
            if (ratings[i]>ratings[i+1])
            {
                candy_count[i]=candy_count[i+1]+1;
            }
        }

        return accumulate(candy_count.begin(),candy_count.end(),0);
    }
};

int main()
{
    Solution sol;
    vector<int> rating = {1,2,87,87,87,2,1};

    cout << sol.candy(rating) << endl;
}