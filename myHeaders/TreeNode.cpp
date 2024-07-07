#include "TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

TreeNode *createBinaryTree(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(nums[0]);
    q.push(root);

    size_t i = 1;
    while (i < nums.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < nums.size() && nums[i] != NULL_NODE)
        {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;

        if (i < nums.size() && nums[i] != NULL_NODE)
        {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Utility function to print the tree in level order (for testing purposes)
void printTreeLevelOrder(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current)
        {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
        else
        {
            cout << "null ";
        }
    }
    cout << endl;
}