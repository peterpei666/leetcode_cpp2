#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int min_dis(int a, int b, int n)
    {
        if (a > b) swap(a, b);
        return min(b - a, a + n - b);
    }
    
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        int n = (int)nums.size();
        int m = (int)queries.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            int target = nums[queries[i]];
            int k = (int)mp[target].size();
            if (k == 1)
            {
                ans[i] = -1;
                continue;
            }
            int idx = (int)(lower_bound(mp[target].begin(), mp[target].end(), queries[i]) - mp[target].begin());
            ans[i] = min(min_dis(mp[target][(idx - 1 + k) % k], queries[i], n), min_dis(queries[i], mp[target][(idx + 1 + k) % k], n));
        }
        return ans;
    }
};
