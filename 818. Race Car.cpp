#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int racecar(int target)
    {
        queue<pair<int, int>> q;
        int ans = 1;
        q.push(make_pair(0, 1));
        while (!q.empty())
        {
            int sz = (int)q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [p, v] = q.front();
                q.pop();
                if (p + v > 100000 || p + v < -100000)
                {
                    continue;
                }
                if (p + v == target)
                {
                    return ans;
                }
                q.push(make_pair(p + v, v * 2));
                if ((p + v > target && v > 0) || (p + v < target && v< 0))
                {
                    q.push(make_pair(p, -v / abs(v)));
                }
            }
            ans++;
        }
        return -1;
    }
};
