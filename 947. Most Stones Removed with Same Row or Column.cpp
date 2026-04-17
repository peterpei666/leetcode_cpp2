#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    DSU(int n) : parent(n), rank(n, 0), count(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
            return true;
        }
        return false;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    int get_count() const
    {
        return count;
    }
};


class Solution
{
public:
    int removeStones(vector<vector<int>>& stones)
    {
        int n = (int)stones.size();
        DSU dsu(n);
        int row[10001];
        int col[10001];
        memset(row, -1, sizeof(row));
        memset(col, -1, sizeof(col));
        for (int i = 0; i < n; i++)
        {
            if (row[stones[i][0]] == -1)
            {
                row[stones[i][0]] = i;
            }
            else
            {
                dsu.unite(i, row[stones[i][0]]);
            }
            if (col[stones[i][1]] == -1)
            {
                col[stones[i][1]] = i;
            }
            else
            {
                dsu.unite(i, col[stones[i][1]]);
            }
        }
        return n - dsu.get_count();
    }
};
