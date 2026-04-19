#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        int in_degree[n];
        memset(in_degree, 0, sizeof(in_degree));
        for (auto& e : edges)
        {
            in_degree[e[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
