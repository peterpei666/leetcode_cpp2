#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {
        int m = (int)succProb.size();
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < m; i++)
        {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], -log(succProb[i])));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], -log(succProb[i])));
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        pq.push(make_pair(0, start_node));
        vector<double> dis(n, INT_MAX);
        dis[start_node] = 0.0;
        while (!pq.empty())
        {
            auto [cur, node] = pq.top();
            pq.pop();
            if (node == end_node)
            {
                return exp(-cur);
            }
            for (auto [next, cost] : graph[node])
            {
                double temp = cur + cost;
                if (temp < dis[next])
                {
                    dis[next] = temp;
                    pq.push(make_pair(temp, next));
                }
            }
        }
        return 0.0;
    }
};
