#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int n = (int)stations.size();
        priority_queue<int> pq;
        int pos = 0;
        int cur = startFuel;
        while (pos < n && stations[pos][0] <= cur)
        {
            pq.push(stations[pos][1]);
            pos++;
        }
        int ans = 0;
        while (!pq.empty())
        {
            if (cur >= target)
            {
                break;
            }
            cur += pq.top();
            pq.pop();
            ans++;
            while (pos < n && stations[pos][0] <= cur)
            {
                pq.push(stations[pos][1]);
                pos++;
            }
        }
        return cur >= target ? ans : -1;
    }
};
