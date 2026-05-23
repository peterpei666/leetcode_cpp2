#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int>& nums)
    {
        int n = (int)nums.size();
        int cnt = nums[0] < nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            cnt += nums[i - 1] > nums[i];
        }
        return cnt <= 1;
    }
};
