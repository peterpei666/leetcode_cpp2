#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(n);
        for (auto& e : dislikes)
        {
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
        }
        bitset<2000> valid;
        bitset<2000> odd;
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
