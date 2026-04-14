#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
    {
        int m = (int)factory.size();
        int n = (int)robot.size();
        long long dp[101][101];
        memset(dp, 0x7f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [&](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        for (int j = 1; j <= m; j++)
        {
            int p = factory[j - 1][0];
            int limit = factory[j - 1][1];
            for (int i = 0; i <= n; i++)
            {
                dp[i][j] = dp[i][j - 1];
                long long dis = 0;
                for (int k = 1; k <= limit && i - k >= 0; k++)
                {
                    dis += abs(robot[i - k] - p);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dis);
                }
            }
        }
        return dp[n][m];
    }
};
