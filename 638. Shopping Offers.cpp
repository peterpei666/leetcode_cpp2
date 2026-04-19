#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
private:
    map<vector<int>, int> memo;
    int n;
    
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> cur) {
        if (memo.count(cur))
        {
            return memo[cur];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += cur[i] * price[i];
        }
        for (const auto& sp : special)
        {
            vector<int> next = cur;
            bool canUse = true;
            for (int i = 0; i < n; i++)
            {
                if (next[i] < sp[i])
                {
                    canUse = false;
                    break;
                }
                next[i] -= sp[i];
            }
            if (canUse)
            {
                ans = min(ans, dfs(price, special, next) + sp.back());
            }
        }
        return memo[cur] = ans;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        memo.clear();
        n = (int)price.size();
        return dfs(price, special, needs);
    }
};
