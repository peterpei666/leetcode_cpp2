#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string processStr(const string& s)
    {
        string ans;
        for (char c : s)
        {
            if (c == '*')
            {
                if (!ans.empty())
                {
                    ans.pop_back();
                }
            }
            else if (c == '#')
            {
                ans.append(ans);
            }
            else if (c == '%')
            {
                reverse(ans.begin(), ans.end());
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
