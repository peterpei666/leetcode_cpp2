#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        bool valid[100] = {false};
        bool odd[100] = {false};
        int n = (int)graph.size();
        for (int start = 0; start < n; start++)
        {
            if (!valid[start])
            {
                valid[start] = true;
                odd[start] = false;
                queue<int> q;
                q.push(start);
                for (int k = 0; !q.empty(); k ^= 1)
                {
                    int sz = (int)q.size();
                    for (int i = 0; i < sz; i++)
                    {
                        int node = q.front();
                        q.pop();
                        for (int next : graph[node])
                        {
                            if (valid[next])
                            {
                                if (odd[next] == k)
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                valid[next] = true;
                                odd[next] = k ^ 1;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
