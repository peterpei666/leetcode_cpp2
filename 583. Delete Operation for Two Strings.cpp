#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDistance(const string& w1, const string& w2)
    {
        int m = (int)w1.size();
        int n = (int)w2.size();
        int dp[2][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            int mask = i & 1;
            int prev = mask ^ 1;
            for (int j = 1; j <= n; j++)
            {
                if (w1[i - 1] == w2[j - 1])
                {
                    dp[mask][j] = dp[prev][j - 1] + 1;
                }
                else
                {
                    dp[mask][j] = max(dp[mask][j - 1], dp[prev][j]);
                }
            }
        }
        return m + n - 2 * dp[m & 1][n];
    }
};
