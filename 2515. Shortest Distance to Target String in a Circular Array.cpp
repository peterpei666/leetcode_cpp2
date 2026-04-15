#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int closestTarget(vector<string>& words, const string& target, int startIndex)
    {
        int n = (int)words.size();
        int ans = 1000;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                ans = min(ans, min(abs(i - startIndex), n - abs(i - startIndex)));
            }
        }
        return ans == 1000 ? -1 : ans;
    }
};
