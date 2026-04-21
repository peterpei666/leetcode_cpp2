#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int>& arr)
    {
        int n = (int)arr.size();
        int pre[n];
        pre[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                pre[i] = pre[i - 1] + 1;
            }
            else
            {
                pre[i] = 0;
            }
        }
        int suf[n];
        suf[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                suf[i] = suf[i + 1] + 1;
            }
            else
            {
                suf[i] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (pre[i] && suf[i])
            {
                ans = max(ans, pre[i] + suf[i] + 1);
            }
        }
        return ans;
    }
};
