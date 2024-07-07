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

        TreeNode *root0 = new TreeNode(root1->val + root2->val);

        queue<TreeNode *> q0, q1, q2;

        q0.push(root0);
        cout << "q0 psuh " << root0->val << endl;
        q1.push(root1->left);
        q1.push(root1->right);
        q2.push(root2->left);
        q2.push(root2->right);

        while (!q0.empty())
        {
            TreeNode *c0 = q0.front();
            q0.pop();
            cout << "\nc0->val: " << c0->val << endl;

            // left node
            cout << "\nleft node" << endl;
            TreeNode *c1 = q1.front();
            q1.pop();
            if (c1)
                cout << "c1->val: " << c1->val << endl;
            else
                cout << "c1 is nullptr" << endl;

            TreeNode *c2 = q2.front();
            q2.pop();
            if (c2)
                cout << "c2->val: " << c2->val << endl;
            else
                cout << "c2 is nullptr" << endl;

            int v1 = 0, v2 = 0;

            if (!c1 && !c2)
                c0->left = nullptr;
            else
            {
                if (!c1)
                {
                    q1.push(nullptr);
                    q1.push(nullptr);
                    q2.push(c2->left);
                    q2.push(c2->right);
                    v2 = c2->val;
                }
                else if (!c2)
                {
                    q1.push(c1->left);
                    q1.push(c1->right);
                    q2.push(nullptr);
                    q2.push(nullptr);
                    v1 = c1->val;
                }
                else
                {
                    q1.push(c1->left);
                    q1.push(c1->right);
                    q2.push(c2->left);
                    q2.push(c2->right);
                    v1 = c1->val;
                    v2 = c2->val;
                }
                c0->left = new TreeNode(v1 + v2);
                q0.push(c0->left);
            }

            // right node
            cout << "\nright node" << endl;
            c1 = q1.front();
            q1.pop();
            if (c1)
                cout << "c1->val: " << c1->val << endl;
            else
                cout << "c1 is nullptr" << endl;

            c2 = q2.front();
            q2.pop();
            if (c2)
                cout << "c2->val: " << c2->val << endl;
            else
                cout << "c2 is nullptr" << endl;

            v1 = 0, v2 = 0;

            if (!c1 && !c2)
                c0->right = nullptr;
            else
            {
                if (!c1)
                {
                    q1.push(nullptr);
                    q1.push(nullptr);
                    q2.push(c2->left);
                    q2.push(c2->right);
                    v2 = c2->val;
                }
                else if (!c2)
                {
                    q1.push(c1->left);
                    q1.push(c1->right);
                    q2.push(nullptr);
                    q2.push(nullptr);
                    v1 = c1->val;
                }
                else
                {
                    q1.push(c1->left);
                    q1.push(c1->right);
                    q2.push(c2->left);
                    q2.push(c2->right);
                    v1 = c1->val;
                    v2 = c2->val;
                }
                c0->right = new TreeNode(v1 + v2);
                q0.push(c0->right);
            }
        }
        return root0;
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