#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int dp[2][n + 1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            int mask = i & 1;
            int prev = mask ^ 1;
            memset(dp[mask], 0, sizeof(dp[0]));
            for (int j = n - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[mask][j] = dp[prev][j + 1] + 1;
                    ans = max(ans, dp[mask][j]);
                }
                else
                {
                    dp[mask][j] = 0;
                }
            }
        }
        return ans;
    }
};
