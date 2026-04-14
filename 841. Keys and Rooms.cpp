#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = (int)rooms.size();
        bool visited[1000] = {0};
        visited[0] = true;
        stack<int> stk;
        stk.push(0);
        while (!stk.empty())
        {
            int t = stk.top();
            stk.pop();
            for (int next : rooms[t])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    stk.push(next);
                }
            }
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            ans &= visited[i];
        }
        return ans;
    }
};
