#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isSubsequence(const string& s, const string& t)
    {
        int m = (int)s.size();
        int n = (int)t.size();
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == m;
    }
};
