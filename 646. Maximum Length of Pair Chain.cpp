#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n = (int)pairs.size();
        sort(pairs.begin(), pairs.end());
        int dp[1000];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
