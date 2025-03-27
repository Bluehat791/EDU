#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void number_notice(vector<vector<int>> &intervals, vector<int> &newInterval, vector<int> &flag_numbers)
    {
        for (size_t j = 0; j < intervals.size(); j++)
        {
            for (size_t i = intervals[j][0]; i < intervals[j][intervals[0].size() - 1]; i++)
            {
                flag_numbers[i] = 1;
            }
        }

        for (size_t i = newInterval[0]; i < newInterval[newInterval.size() - 1]; i++)
        {
            flag_numbers[i] = 1;
        }
    }

    int max_element_in(vector<vector<int>> &intervals)
    {
        int max = INT_MIN;
        for (int i = 0; i < intervals.size(); i++)
        {
            for (int j = 0; j < intervals[0].size(); j++)
            {
                if (intervals[i][j] > max)
                {
                    max = intervals[i][j];
                }
            }
        }
        return max;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int max = max_element_in(intervals);
        vector<int> flag_number;
        if (max != INT_MIN)
        {
            flag_number.resize(max, 0);
        }
        else
        {
            auto new_max = max_element(newInterval.begin(), newInterval.end());
            flag_number.resize(*new_max, 0);
        }

        number_notice(intervals, newInterval, flag_number);

        vector<vector<int>> result;

        for (size_t i = 1; i < flag_number.size(); i++)
        {
            vector<int> tmp;
            int x = flag_number[i];
            if (x != 0)
                tmp.push_back(i);
            else
                continue;

            while (x == 1)
            {
                i++;
                if (i < flag_number.size())
                {
                    x = flag_number[i];
                }
                else
                {
                    break;
                }
            }
            tmp.push_back(i);

            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newIntervals = {2, 7};
    sol.insert(intervals, newIntervals);
}