#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(const string& word)
    {
        int n = (int)word.size();
        int upper = 0;
        int lower = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                upper |= 1 << (word[i] - 'A');
            }
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                lower |= 1 << (word[i] - 'a');
            }
        }
        return __builtin_popcount(upper & lower);
    }
};
