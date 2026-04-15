#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int find(int dp[201][201], int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        if (dp[l][r] != 0x7f7f7f7f)
        {
            return dp[l][r];
        }
        for (int i = l; i <= r; i++)
        {
            dp[l][r] = min(dp[l][r], max(find(dp, l, i - 1), find(dp, i + 1, r)) + i);
        }
        return dp[l][r];
    }
    
public:
    int getMoneyAmount(int n)
    {
        int dp[201][201];
        memset(dp, 0x7f, sizeof(dp));
        return find(dp, 1, n);
    }
};
