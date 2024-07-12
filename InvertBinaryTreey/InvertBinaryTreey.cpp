#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    // recursive
    // TreeNode *invertTree(TreeNode *root)
    // {
    //     if (!root)
    //         return root;

    //     swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);

    //     return root;
    // }

    // not recursive
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        stack<TreeNode *> stack;
        stack.push(root);

        while (!stack.empty())
        {
            auto *temp = stack.top();
            stack.pop();

            swap(temp->left, temp->right);

            if (temp->right)
                stack.push(temp->right);

            if (temp->left)
                stack.push(temp->left);
        }

        return root;
    }
};

int main()
{
    auto *root = createBinaryTree({4, 2, 7, 1, 3, 6, 9});
    // auto *root = createBinaryTree({2, 1, 3});
    // auto *root = createBinaryTree({});

    Solution sol;

    auto *answer = sol.invertTree(root);

    printTreeLevelOrder(answer);

    return 0;
}