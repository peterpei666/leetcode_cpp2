#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        int n = (int)arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr[n - 1];
    }
};
