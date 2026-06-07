#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        TreeNode* node[100002] = {0};
        bool child[100002] = {0};
        for (auto& d : descriptions)
        {
            if (node[d[0]] == nullptr)
            {
                node[d[0]] = new TreeNode(d[0]);
            }
            if (node[d[1]] == nullptr)
            {
                node[d[1]] = new TreeNode(d[1]);
            }
            child[d[1]] = true;
            if (d[2])
            {
                node[d[0]]->left = node[d[1]];
            }
            else
            {
                node[d[0]]->right = node[d[1]];
            }
        }
        for (int i = 0; i <= 100000; i++)
        {
            if (node[i] && !child[i])
            {
                return node[i];
            }
        }
        return nullptr;
    }
};
