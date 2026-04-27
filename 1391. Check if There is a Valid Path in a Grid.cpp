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
    bool hasValidPath(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        DSU dsu(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i)
                {
                    if((grid[i][j] == 2 || grid[i][j] == 5 || grid[i][j] == 6) && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
                    {
                        dsu.unite(i * n + j , (i - 1) * n + j);
                    }
                }
                if(j)
                {
                    if((grid[i][j] == 1 || grid[i][j] == 3 || grid[i][j] == 5) && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
                    {
                        dsu.unite(i * n + j, i * n + j - 1);
                    }
                }
            }
        }
        return dsu.connected(0, m * n - 1);
    }
};
