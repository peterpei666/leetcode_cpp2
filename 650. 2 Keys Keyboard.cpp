#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSteps(int n)
    {
        int dp[n + 1];
        memset(dp, 0x7f, sizeof(dp));
        dp[1] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                dp[j] = min(dp[j], dp[i] + j / i);
            }
        }
        return dp[n];
    }
};
