#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd)
    {
        int first;
        int n = (int)ls.size();
        int m = (int)ws.size();
        int ans = INT_MAX;
        first = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            first = min(first, ls[i] + ld[i]);
        }
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, max(first, ws[i]) + wd[i]);
        }
        first = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            first = min(first, ws[i] + wd[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, max(first, ls[i]) + ld[i]);
        }
        return ans;
    }
};
