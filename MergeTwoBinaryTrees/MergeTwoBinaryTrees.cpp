#include "../myHeaders/TreeNode.h"
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

int main()
{
    // TreeNode *root1 = createBinaryTree({1, 3, 2, 5});
    // TreeNode *root2 = createBinaryTree({2, 1, 3, NULL_NODE, 4, NULL_NODE, 7});
    // TreeNode *root1 = createBinaryTree({1});
    // TreeNode *root2 = createBinaryTree({1, 2});
    // TreeNode *root1 = createBinaryTree({1, 2});
    // TreeNode *root2 = createBinaryTree({0, NULL_NODE, 3});
    TreeNode *root1 = createBinaryTree({3, 4, 5, 1, 2});
    TreeNode *root2 = createBinaryTree({4, 1, 2});

    Solution sol;
    TreeNode *merged = sol.mergeTrees(root1, root2);

    printTreeLevelOrder(merged);

    return 0;
}