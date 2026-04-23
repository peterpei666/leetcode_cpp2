#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<long long> distance(vector<int>& nums)
    {
        int n = (int)nums.size();
        unordered_map<int, long long> cur;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cur[nums[i]] += i;
            cnt[nums[i]]++;
        }
        vector<long long> ans(n);
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
        {
            cur[nums[i]] -= (i - pos[nums[i]]) * cnt[nums[i]];
            pos[nums[i]] = i;
            cnt[nums[i]] -= 2;
            ans[i] = cur[nums[i]];
        }
        return ans;
    }
};
