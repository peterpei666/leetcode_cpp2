#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        int n = (int)coins.size();
        long long dp[5001] = {0};
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j] > INT_MAX)
                {
                    break;
                }
                dp[j] += dp[j - coins[i]];
            }
        }
        return (int)dp[amount];
    }
};
