#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int>& gain)
    {
        int n = (int)gain.size();
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cur += gain[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
