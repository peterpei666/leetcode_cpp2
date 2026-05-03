#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool rotateString(const string& s, const string& goal)
    {
        int m = (int)s.size();
        int n = (int)goal.size();
        if (m != n)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            bool valid = true;
            for (int k = 0; k < n; k++)
            {
                if (s[(i + k) % n] != goal[k])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                return true;
            }
        }
        return false;
    }
};
