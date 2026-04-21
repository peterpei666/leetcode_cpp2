#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int uniqueLetterString(const string& s)
    {
        vector<int> pos[26];
        for (int i = 0; i < 26; i++)
        {
            pos[i].push_back(-1);
        }
        int n = (int)s.size();
        for (int i = 0; i < n; i++)
        {
            pos[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; i++)
        {
            pos[i].push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int sz = (int)pos[i].size();
            for (int j = 1; j < sz - 1; j++)
            {
                ans += (pos[i][j] - pos[i][j - 1]) * (pos[i][j + 1] - pos[i][j]);
            }
        }
        return ans;
    }
};
