#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool splitArraySameAverage(vector<int>& nums)
    {
        int n = (int)nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int dp[total + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[nums[0]] = 2;
        for (int i = 1; i < n; i++)
        {
            for (int j = total - nums[i]; j >= 0; j--)
            {
                dp[j + nums[i]] |= dp[j] << 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if ((total * i) % n == 0 && (dp[total * i / n] & (1 << i)))
            {
                return true;
            }
        }
        return false;
    }
};
