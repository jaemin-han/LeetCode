#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    // int maxDepth(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;

    //     int max_depth = 0;
    //     stack<pair<TreeNode *, int>> stack;

    //     stack.push({root, 1});

    //     while (!stack.empty())
    //     {
    //         auto temp = stack.top();
    //         auto *cur = temp.first;
    //         auto depth = temp.second;
    //         stack.pop();

    //         max_depth = max(max_depth, depth);

    //         if (cur->left)
    //             stack.push({cur->left, depth + 1});

    //         if (cur->right)
    //             stack.push({cur->right, depth + 1});
    //     }
    //     return max_depth;
    // }

    // recursive ver
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    auto *root = createBinaryTree({3, 9, 20, NULL_NODE, NULL_NODE, 15, 7});

    Solution sol;

    cout << sol.maxDepth(root) << endl;

    return 0;
}