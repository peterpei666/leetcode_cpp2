#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int openLock(vector<string>& deadends, const string& target)
    {
        unordered_set<string> visited;
        visited.insert("0000");
        unordered_set<string> block(deadends.begin(), deadends.end());
        queue<string> q;
        q.push("0000");
        if (block.count("0000"))
        {
            return -1;
        }
        int ans = 0;
        while (!q.empty())
        {
            int sz = (int)q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                if (cur == target)
                {
                    return ans;
                }
                for (int k = 0; k < 4; k++)
                {
                    string temp = cur;
                    temp[k] = (cur[k] + 1 - '0') % 10 + '0';
                    if (!visited.count(temp) && !block.count(temp))
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                    temp[k] = (cur[k] + 9 - '0') % 10 + '0';
                    if (!visited.count(temp) && !block.count(temp))
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                    temp[k] = cur[k];
                }
            }
            ans++;
        }
        return -1;
    }
};
