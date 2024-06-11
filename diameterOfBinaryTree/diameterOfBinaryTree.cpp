#include "../myHeaders/TreeNode.h"

#include <iostream>
using namespace std;

class Solution
{
public:
    int diameter;

    int diameterOfBinaryTree(TreeNode *root)
    {
        diameter = 0;
        MaxEdge(root);
        return diameter;
    }
    int MaxEdge(TreeNode *node)
    {
        if (!node)
            return 0;

        int left = 0;
        if (node->left)
            left = MaxEdge(node->left) + 1;
        int right = 0;
        if (node->right)
            right = MaxEdge(node->right) + 1;

        diameter = max(diameter, left + right);
        return max(left, right);
    }
};

int main()
{
    TreeNode *tree = createBinaryTree({1, 2, 3, 4});

    Solution sol;

    printTreeLevelOrder(tree);
    cout << sol.diameterOfBinaryTree(tree) << endl;
    // cout << sol.MaxEdge(tree) << endl;
    return 0;
}