#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int>& nums)
    {
        int n = (int)nums.size();
        int total = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
            cur += i * nums[i];
        }
        int ans = cur;
        for (int i = n - 1; i >= 0; i--)
        {
            cur = cur + total - n * nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
