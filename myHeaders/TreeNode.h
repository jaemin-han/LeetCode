#pragma once

#include <vector>
#include <limits> // for windows, I dont know why

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createBinaryTree(const std::vector<int> &nums);
void printTreeLevelOrder(TreeNode *root);

const int NULL_NODE = std::numeric_limits<int>::min();
