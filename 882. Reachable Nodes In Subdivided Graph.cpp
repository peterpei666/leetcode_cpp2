#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n)
    {
        vector<vector<pair<int, int>>> mp(n);
        for (auto& e : edges)
        {
            mp[e[0]].push_back(make_pair(e[1], e[2]));
            mp[e[1]].push_back(make_pair(e[0], e[2]));
        }
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(maxMoves, 0));
        vector<int> dis(n, -1);
        dis[0] = maxMoves;
        while (!pq.empty())
        {
            auto [move, node] = pq.top();
            pq.pop();
            if (dis[node] > move)
            {
                continue;
            }
            for (auto [next, cost] : mp[node])
            {
                if (move - cost - 1 > dis[next])
                {
                    dis[next] = move - cost - 1;
                    pq.push(make_pair(move - cost - 1, next));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] >= 0)
            {
                ans++;
            }
        }
        for (auto& e : edges)
        {
            int a = dis[e[0]] == -1 ? 0 : dis[e[0]];
            int b = dis[e[1]] == -1 ? 0 : dis[e[1]];
            ans += min(e[2], a + b);
        }
        return ans;
    }
};
