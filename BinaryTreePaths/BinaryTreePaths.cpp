#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;
// Definition for a binary tree node.
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!deque.empty())
            deque.clear();

        if (!answer.empty())
            answer.clear();

        deque.push_back(root->val);
        DFS(root);
        return answer;
    }
    void DFS(TreeNode *node)
    {
        if (!node->left && !node->right)
        {
            answer.push_back(make_string());
            return;
        }

        if (node->left)
        {
            deque.push_back(node->left->val);
            DFS(node->left);
            deque.pop_back();
        }

        if (node->right)
        {
            deque.push_back(node->right->val);
            DFS(node->right);
            deque.pop_back();
        }
    }

    string make_string()
    {
        string temp = "";
        for (auto iter = deque.begin(); iter != deque.end(); ++iter)
        {
            temp += to_string(*iter);
            if (iter != deque.end() - 1)
                temp += "->";
        }
        return temp;
    }
    deque<int> deque;
    vector<string> answer;
};

int main()
{
    // vector<int> nums = {1, 2, 3, 4, NULL_NODE, 5};
    vector<int> nums = {-64, 12, 18, -4, -53, NULL_NODE, 76, NULL_NODE, -51, NULL_NODE, NULL_NODE, -93, 3, NULL_NODE, -31, 47, NULL_NODE, 3, 53, -81, 33, 4, NULL_NODE, -51, -44, -60, 11, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 78, NULL_NODE, -35, -64, 26, -81, -31, 27, 60, 74, NULL_NODE, NULL_NODE, 8, -38, 47, 12, -24, NULL_NODE, -59, -49, -11, -51, 67, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, -67, NULL_NODE, -37, -19, 10, -55, 72, NULL_NODE, NULL_NODE, NULL_NODE, -70, 17, -4, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 3, 80, 44, -88, -91, NULL_NODE, 48, -90, -30, NULL_NODE, NULL_NODE, 90, -34, 37, NULL_NODE, NULL_NODE, 73, -38, -31, -85, -31, -96, NULL_NODE, NULL_NODE, -18, 67, 34, 72, NULL_NODE, -17, -77, NULL_NODE, 56, -65, -88, -53, NULL_NODE, NULL_NODE, NULL_NODE, -33, 86, NULL_NODE, 81, -42, NULL_NODE, NULL_NODE, 98, -40, 70, -26, 24, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 92, 72, -27, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, -67, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, -54, -66, -36, NULL_NODE, -72, NULL_NODE, NULL_NODE, 43, NULL_NODE, NULL_NODE, NULL_NODE, -92, -1, -98, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 39, -84, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, -93, NULL_NODE, NULL_NODE, NULL_NODE, 98};
    // vector<int> nums = {1};

    TreeNode *root = createBinaryTree(nums);
    printTreeLevelOrder(root);

    Solution sol;
    vector<string> answer = sol.binaryTreePaths(root);
    for (const auto &ans : answer)
    {
        cout << ans << endl;
        ;
    }
}