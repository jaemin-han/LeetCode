#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    // BFS version
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> queue;

        queue.push(root);

        int i = 0;
        while (!queue.empty())
        {
            i++;
            int size = queue.size();
            for (int j = 0; j < size; j++)
            {
                TreeNode *cur = queue.front();
                queue.pop();

                if (!cur->left && !cur->right)
                    return i;

                if (cur->left)
                    queue.push(cur->left);

                if (cur->right)
                    queue.push(cur->right);
            }
        }
        return -1;
    }

    // recursion version
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return min(left, right) ? min(left, right) + 1 : max(left, right) + 1;
    }
};

int main()
{
    // TreeNode *root = createBinaryTree({3, 9, 20, NULL_NODE, NULL_NODE, 15, 7});
    TreeNode *root = createBinaryTree({2, NULL_NODE, 3, NULL_NODE, 4, NULL_NODE, 5, NULL_NODE, 6});

    Solution sol;

    cout << sol.minDepth(root) << endl;
    return 0;
}