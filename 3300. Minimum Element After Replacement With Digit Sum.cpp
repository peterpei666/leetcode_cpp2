#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minElement(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 1000;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            while (nums[i])
            {
                temp += nums[i] % 10;
                nums[i] /= 10;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};
