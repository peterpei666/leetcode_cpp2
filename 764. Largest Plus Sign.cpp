#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        bool mp[n][n];
        memset(mp, 0, sizeof(mp));
        for (auto& m : mines)
        {
            mp[m[0]][m[1]] = true;
        }
        int ans[n][n];
        memset(ans, 0x1, sizeof(ans));
        for (int i = 0; i < n; i++)
        {
            int cur;
            cur = 0;
            for (int j = 0; j < n; j++)
            {
                if (mp[i][j])
                {
                    cur = 0;
                }
                else
                {
                    cur++;
                }
                ans[i][j] = min(ans[i][j], cur);
            }
            cur = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (mp[i][j])
                {
                    cur = 0;
                }
                else
                {
                    cur++;
                }
                ans[i][j] = min(ans[i][j], cur);
            }
        }
        for (int j = 0; j < n; j++)
        {
            int cur;
            cur = 0;
            for (int i = 0; i < n; i++)
            {
                if (mp[i][j])
                {
                    cur = 0;
                }
                else
                {
                    cur++;
                }
                ans[i][j] = min(ans[i][j], cur);
            }
            cur = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (mp[i][j])
                {
                    cur = 0;
                }
                else
                {
                    cur++;
                }
                ans[i][j] = min(ans[i][j], cur);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = max(res, ans[i][j]);
            }
        }
        return res;
    }
};
