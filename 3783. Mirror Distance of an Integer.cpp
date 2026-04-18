#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int mirrorDistance(int n)
    {
        int temp = n;
        long long rev = 0;
        while (temp)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return (int)abs(rev - n);
    }
};
