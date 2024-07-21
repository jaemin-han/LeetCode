#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> candidate;
        queue<TreeNode *> rootq;

        rootq.push(root);

        while (!rootq.empty())
        {
            TreeNode *current = rootq.front();
            rootq.pop();

            if (current->val == subRoot->val)
                candidate.push(current);

            if (current->left)
                rootq.push(current->left);

            if (current->right)
                rootq.push(current->right);
        }

        while (!candidate.empty())
        {
            queue<TreeNode *> rootq;
            queue<TreeNode *> subq;

            rootq.push(candidate.front());
            candidate.pop();
            subq.push(subRoot);

            while (!rootq.empty() && !subq.empty())
            {
                TreeNode *rootCur = rootq.front();
                rootq.pop();
                TreeNode *subCur = subq.front();
                subq.pop();

                if (rootCur->val != subCur->val)
                    break;

                if (subCur->left && rootCur->left)
                {
                    subq.push(subCur->left);
                    rootq.push(rootCur->left);
                }
                else if (!subCur->left && !rootCur->left)
                {
                }
                else
                    break;

                if (subCur->right && rootCur->right)
                {
                    subq.push(subCur->right);
                    rootq.push(rootCur->right);
                }
                else if (!subCur->right && !rootCur->right)
                {
                }
                else
                    break;

                if (rootq.empty() && subq.empty())
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    TreeNode *root = createBinaryTree({3, 4, 5, 1, 2});
    TreeNode *subRoot = createBinaryTree({4, 1, 2});
    // TreeNode *root = createBinaryTree({3, 4, 5, 1, 2, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 0});
    // TreeNode *subRoot = createBinaryTree({4, 1, 2});

    Solution sol;

    cout << boolalpha << sol.isSubtree(root, subRoot) << endl;

    return 0;
}