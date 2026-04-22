#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class MKAverage
{
private:
    int sz, m, k;
    int pos;
    long long sum;
    multiset<int> low;
    multiset<int> mid;
    multiset<int> high;
    vector<int> q;
    
    void remove(int x)
    {
        if (x <= *low.rbegin())
        {
            low.erase(low.find(x));
        }
        else if (x <= *mid.rbegin())
        {
            sum -= x;
            mid.erase(mid.find(x));
        }
        else
        {
            high.erase(high.find(x));
        }
        if (low.size() < k)
        {
            low.insert(*mid.begin());
            sum -= *mid.begin();
            mid.erase(mid.begin());
        }
        if (mid.size() < sz)
        {
            mid.insert(*high.begin());
            sum += *high.begin();
            high.erase(high.begin());
        }
    }
    
public:
    MKAverage(int m, int k) : m(m), k(k), sz(m - 2 * k), sum(0), pos(0)
    {
        q = vector<int>(m);
    }
    
    void addElement(int num)
    {
        if (pos >= m)
        {
            remove(q[pos % m]);
        }
        q[pos % m] = num;
        pos++;
        low.insert(num);
        if (low.size() > k)
        {
            auto it = prev(low.end());
            mid.insert(*it);
            sum += *it;
            low.erase(it);
        }
        if (mid.size() > sz)
        {
            auto it = prev(mid.end());
            high.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }
    
    int calculateMKAverage()
    {
        if (pos < m)
        {
            return -1;
        }
        return (int)(sum / sz);
    }
};
