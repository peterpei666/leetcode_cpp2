#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = (int)intervals.size();
        sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });
        int cnt = 0;
        int cur = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < cur)
            {
                cnt++;
            }
            else
            {
                cur = intervals[i][1];
            }
        }
        return cnt;
    }
};
