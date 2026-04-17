#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int rev(int x)
    {
        int ans = 0;
        while (x)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    
public:
    int minMirrorPairDistance(vector<int>& nums)
    {
        int n = (int)nums.size();
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[rev(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
