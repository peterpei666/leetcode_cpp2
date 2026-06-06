#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int>& nums)
    {
        int n = (int)nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int left = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = abs(total - 2 * left - nums[i]);
            left += nums[i];
        }
        return ans;
    }
};
