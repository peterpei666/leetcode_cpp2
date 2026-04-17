#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSwapsCouples(vector<int>& row)
    {
        int n = (int)row.size();
        int pos[60];
        int ptn[60];
        for (int i = 0; i < n; i++)
        {
            pos[row[i]] = i;
            ptn[i] = i & 1 ? i - 1 : i + 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = ptn[pos[ptn[row[i]]]]; j != i; j = ptn[pos[ptn[row[i]]]])
            {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ans++;
            }
        }
        return ans;
    }
};
