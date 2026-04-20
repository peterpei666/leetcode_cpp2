#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources)
    {
        vector<vector<int>> mp(n, vector<int>(m, -1));
        sort(sources.begin(), sources.end(), [&](auto& a, auto& b) { return a[2] > b[2]; });
        queue<pair<int, int>> q;
        for (auto& s : sources)
        {
            mp[s[0]][s[1]] = s[2];
            q.push(make_pair(s[0], s[1]));
        }
        int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == -1)
                {
                    mp[nx][ny] = mp[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return mp;
    }
};
