#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(const string& s)
    {
        int n = (int)s.size();
        int dp[2][1001] = {0};
        for (int i = 1; i <= n; i++)
        {
            int mask = i & 1;
            int prev = mask ^ 1;
            memset(dp[mask], 0, sizeof(dp[0]));
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s[n - j])
                {
                    dp[mask][j] = 1 + dp[prev][j - 1];
                }
                else
                {
                    dp[mask][j] = max(dp[prev][j], dp[mask][j - 1]);
                }
            }
        }
        return dp[n & 1][n];
    }
};
