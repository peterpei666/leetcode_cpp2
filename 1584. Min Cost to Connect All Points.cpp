#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = (int)points.size();
        bitset<1000> visited;
        int cnt = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push(make_pair(0, 0));
        int ans = 0;
        while (!pq.empty() && cnt < n)
        {
            auto [cost, node] = pq.top();
            pq.pop();
            if (visited.test(node))
            {
                continue;
            }
            ans += cost;
            visited.set(node);
            cnt++;
            for (int i = 0; i < n; i++)
            {
                if (!visited.test(i))
                {
                    pq.push(make_pair(abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]), i));
                }
            }
        }
        return ans;
    }
};
