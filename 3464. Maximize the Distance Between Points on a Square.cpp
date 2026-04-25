#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistance(int side, vector<vector<int>>& points, int k)
    {
        int n = (int)points.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++)
        {
            int x = points[i][0], y = points[i][1];
            if (y == 0)
            {
                pos[i] = x;
            }
            else if (x == side)
            {
                pos[i] = 1LL * side + y;
            }
            else if (y == side)
            {
                pos[i] = 3LL * side - x;
            }
            else
            {
                pos[i] = 4LL * side - y;
            }
        }
        sort(pos.begin(), pos.end());
        
        auto valid = [&](int d) -> bool
        {
            for (int i = 0; i < n; i++)
            {
                int ptr = i;
                int cnt = 1;
                while (cnt < k)
                {
                    long long tar = pos[ptr] + d;
                    auto it = lower_bound(pos.begin(), pos.end(), tar);
                    if (it == pos.end())
                    {
                        break;
                    }
                    ptr = (int)(it - pos.begin());
                    cnt++;
                    if (d + pos[ptr] > pos[i] + 4LL * side)
                    {
                        cnt = 0;
                        break;
                    }
                }
                if (cnt == k)
                {
                    return true;
                }
            }
            return false;
        };
        
        int l = 0, r = side;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (valid(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
