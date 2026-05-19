#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();
        int p1 = 0;
        int p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            while (p1 < n1 && p2 < n2 && nums1[p1] < nums2[p2])
            {
                p1++;
            }
            while (p1 < n1 && p2 < n2 && nums1[p1] > nums2[p2])
            {
                p2++;
            }
            if (p1 < n1 && p2 < n2 && nums1[p1] == nums2[p2])
            {
                return nums1[p1];
            }
        }
        return -1;
    }
};
