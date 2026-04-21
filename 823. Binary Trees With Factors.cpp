#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        int n = (int)arr.size();
        const int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> dp;
        for (int i : arr)
        {
            dp[i] = 1;
        }
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < k; i++)
            {
                if (arr[k] % arr[i] == 0)
                {
                    int j = arr[k] / arr[i];
                    if (dp.count(j))
                        dp[arr[k]] = (dp[arr[k]] + 1LL * dp[arr[i]] * dp[j]) % mod;
                }
            }
        }
        int ans = 0;
        for (auto [_, val] : dp)
        {
            ans = (ans + val) % mod;
        }
        return ans;
    }
};
