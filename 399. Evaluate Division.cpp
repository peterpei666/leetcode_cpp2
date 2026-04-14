#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    double dfs(const string& node, double cur, const string& target, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>>& graph)
    {
        if (node == target)
        {
            return cur;
        }
        for (auto& [next, val] : graph[node])
        {
            if (!visited.count(next))
            {
                visited.insert(next);
                double temp = dfs(next, cur * val, target, visited, graph);
                if (temp != -1.0)
                {
                    return temp;
                }
            }
        }
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = (int)equations.size();
        for (int i = 0; i < n; i++)
        {
            string u = equations[i][0], v = equations[i][1];
            graph[u].push_back(make_pair(v, values[i]));
            graph[v].push_back(make_pair(u, 1 / values[i]));
        }
        int m = (int)queries.size();
        vector<double> ans(m);
        for (int i = 0; i < m; i++)
        {
            string u = queries[i][0], v = queries[i][1];
            if (!graph.count(u) || !graph.count(v))
            {
                ans[i] = -1.0;
            }
            else
            {
                unordered_set<string> visited;
                ans[i] = dfs(u, 1.0, v, visited, graph);
            }
        }
        return ans;
    }
};
