#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for (auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> dis(n, 0);
        vector<int> cnt(n, 1);
        
        function<void(int, int)> dfs1 = [&](int p, int u)
        {
            for (int v : graph[u])
            {
                if (p != v)
                {
                    dfs1(u, v);
                    cnt[u] += cnt[v];
                    dis[u] += dis[v] + cnt[v];
                }
            }
        };
        
        function<void(int, int)> dfs2 = [&](int p, int u)
        {
            for (int v : graph[u])
            {
                if (p != v)
                {
                    dis[v] = dis[u] + n - cnt[v] * 2;
                    dfs2(u, v);
                }
            }
        };
        
        dfs1(-1, 0);
        dfs2(-1, 0);
        return dis;
    }
};
