#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        unordered_map<int, vector<int>> graph;
        for (auto& e : connections)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> dfn(n, -1);
        vector<int> low(n, -1);
        int timer = 0;
        vector<vector<int>> ans;
        stack<pair<pair<int, int>, int>> stk;
        stk.push(make_pair(make_pair(0, -1), 0));
        while (!stk.empty())
        {
            auto [a, idx] = stk.top();
            auto [u, p] = a;
            if (idx == 0)
            {
                if (dfn[u] != -1)
                {
                    stk.pop();
                    continue;
                }
                dfn[u] = low[u] = timer;
                timer++;
            }
            if (idx < graph[u].size())
            {
                int v = graph[u][idx];
                stk.pop();
                stk.push(make_pair(make_pair(u, p), idx + 1));
                if (v == p)
                {
                    continue;
                }
                if (dfn[v] == -1)
                {
                    stk.push(make_pair(make_pair(v, u), 0));
                }
                else
                {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            else
            {
                stk.pop();
                if (p != -1)
                {
                    low[p] = min(low[p], low[u]);
                    if (low[u] > dfn[p])
                    {
                        ans.push_back({p, u});
                    }
                }
            }
        }
        return ans;
    }
};
