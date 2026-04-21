#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        int n = (int)nums1.size();
        int v0 = 0, v1 = 1;
        for (int i = 1; i < n; i++)
        {
            int n0 = 1e9;
            int n1 = 1e9;
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
            {
                n0 = min(n0, v0);
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i])
            {
                n0 = min(n0, v1);
            }
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
            {
                n1 = min(n1, v0 + 1);
            }
            if (nums2[i - 1] < nums2[i] && nums1[i - 1] < nums1[i])
            {
                n1 = min(n1, v1 + 1);
            }
            v0 = n0;
            v1 = n1;
        }
        return min(v0, v1);
    }
};
