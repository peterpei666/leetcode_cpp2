#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int count(const string& s, int l, int r, int n)
    {
        int ans = 0;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            ans++;
            l--;
            r++;
        }
        return ans;
    }
    
public:
    int countSubstrings(const string& s)
    {
        int n = (int)s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += count(s, i, i, n) + count(s, i, i + 1, n);
        }
        return ans;
    }
};
