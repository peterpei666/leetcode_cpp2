#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        vector<int> arr;
        for (auto& row : grid)
        {
            for (int i : row)
            {
                arr.push_back(i);
            }
        }
        sort(arr.begin(), arr.end());
        int n = (int)arr.size();
        int tar = arr[n / 2];
        int ans = 0;
        for (int i : arr)
        {
            if (i % x != tar % x)
            {
                return -1;
            }
            ans += abs(tar - i) / x;
        }
        return ans;
    }
};
