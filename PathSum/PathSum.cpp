#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        stack.push(make_pair(root, root->val));

        while (!stack.empty())
        {
            TreeNode *cur = stack.top().first;
            int val = stack.top().second;
            stack.pop();

            if (!cur->left && !cur->right && val == targetSum)
                return true;

            if (cur->right)
                stack.push(make_pair(cur->right, val + cur->right->val));
            if (cur->left)
                stack.push(make_pair(cur->left, val + cur->left->val));
        }
        return false;
    }
    stack<pair<TreeNode *, int>> stack;
};

int main()
{
    vector<int> nums = {5, 4, 8, 11, NULL_NODE, 13, 4, 7, 2, NULL_NODE, NULL_NODE, NULL_NODE, 1};
    TreeNode *node = createBinaryTree(nums);
    printTreeLevelOrder(node);

    Solution sol;

    cout << boolalpha << sol.hasPathSum(node, 22) << endl;

    return 0;
}