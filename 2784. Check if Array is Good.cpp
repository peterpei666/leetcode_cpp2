#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] != 1)
        {
            return false;
        }
        int n = (int)nums.size() - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] != nums[i] + 1)
            {
                return false;
            }
        }
        return nums[n] == n;
    }
};
