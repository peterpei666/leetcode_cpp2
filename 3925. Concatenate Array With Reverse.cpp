#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> concatWithReverse(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> ans(2 * n);
        memcpy(&ans[0], &nums[0], sizeof(int) * n);
        memcpy(&ans[n], &nums[0], sizeof(int) * n);
        reverse(ans.begin() + n, ans.end());
        return ans;
    }
};
