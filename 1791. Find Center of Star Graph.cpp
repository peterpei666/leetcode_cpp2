#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int n = (int)edges.size();
        bool visited[100001] = {0};
        for (int i = 0; i < n; i++)
        {
            if (visited[edges[i][0]])
            {
                return edges[i][0];
            }
            visited[edges[i][0]] = true;
            if (visited[edges[i][1]])
            {
                return edges[i][1];
            }
            visited[edges[i][1]] = true;
        }
        return -1;
    }
};
