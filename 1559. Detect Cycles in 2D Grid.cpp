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
    bool containsCycle(vector<vector<char>>& grid)
    {
        int r = (int)grid.size();
        int c = (int)grid[0].size();
        DSU dsu(r * c);
        for (int i = 0; i < r - 1; i++)
        {
            int ridx = i * c;
            for (int j = 0; j < c - 1; j++)
            {
                int cur = ridx + j;
                int alpha = grid[i][j];
                if (grid[i + 1][j] == alpha && !dsu.unite(cur + c, cur))
                {
                    return true;
                }
                if (grid[i][j + 1] == alpha && !dsu.unite(cur + 1, cur))
                {
                    return true;
                }
            }
            int cur = i * c + c - 1;
            int alpha = grid[i][c - 1];
            if (grid[i + 1][c - 1] == alpha && !dsu.unite(cur + c, cur))
            {
                return true;
            }
        }
        int ridx = (r - 1) * c;
        for (int j = 0; j < c - 1; j++)
        {
            int cur = ridx + j;
            char alpha = grid[r - 1][j];
            if (grid[r - 1][j + 1] == alpha && !dsu.unite(cur + 1, cur))
            {
                return true;
            }
        }
        return false;
    }
};
