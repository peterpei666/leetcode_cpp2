#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int>& cost)
    {
        int n = (int)cost.size();
        sort(cost.begin(), cost.end(), greater<>());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 3 != 2)
            {
                ans += cost[i];
            }
        }
        return ans;
    }
};
