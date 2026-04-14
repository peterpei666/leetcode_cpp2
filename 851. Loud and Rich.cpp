#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>>& graph, vector<int>& ans, int cur, vector<int>& quiet)
    {
        if (ans[cur] != -1)
        {
            return ans[cur];
        }
        ans[cur] = cur;
        for (int next : graph[cur])
        {
            int t = dfs(graph, ans, next, quiet);
            if (quiet[ans[cur]] > quiet[t])
            {
                ans[cur] = t;
            }
        }
        return ans[cur];
    }
    
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        int n = (int)quiet.size();
        vector<vector<int>> graph(n);
        for (auto& e : richer)
        {
            graph[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            dfs(graph, ans, i, quiet);
        }
        return ans;
    }
};
