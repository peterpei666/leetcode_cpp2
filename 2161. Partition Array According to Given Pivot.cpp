#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        int n = (int)nums.size();
        vector<int> ans;
        vector<int> temp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                ans.push_back(nums[i]);
            }
            else if (nums[i] > pivot)
            {
                temp.push_back(nums[i]);
            }
            else
            {
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ans.push_back(pivot);
        }
        for (int i : temp)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
