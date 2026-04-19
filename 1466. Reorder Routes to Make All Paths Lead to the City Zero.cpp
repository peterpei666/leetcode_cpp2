#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : connections)
        {
            graph[e[1]].push_back(make_pair(e[0], 0));
            graph[e[0]].push_back(make_pair(e[1], 1));
        }
        
        function<int(int, int)> dfs = [&](int parent, int node) -> int
        {
            int ans = 0;
            for (auto [next, cost] : graph[node])
            {
                if (parent != next)
                {
                    ans += cost + dfs(node, next);
                }
            }
            return ans;
        };
        
        return dfs(-1, 0);
    }
};
