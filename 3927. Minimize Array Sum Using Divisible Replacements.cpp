#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minArraySum(vector<int>& nums)
    {
        int cnt[100005] = {0};
        int m = 0;
        for (int x : nums)
        {
            m = max(m, x);
            cnt[x]++;
        }
        long long ans = 0;
        for (int x = 0; x <= m; x++)
        {
            if (cnt[x])
            {
                for (int t = x; t <= m + 1; t += x)
                {
                    if (cnt[t])
                    {
                        ans += 1LL * cnt[t] * x;
                        cnt[t] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
