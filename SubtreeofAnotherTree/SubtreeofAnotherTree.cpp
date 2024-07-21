#include "../myHeaders/TreeNode.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    /* honest way
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
    */

    /*Recursive ver
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        if (root->val != subRoot->val)
            return false;

        bool left = isIdentical(root->left, subRoot->left);
        bool right = isIdentical(root->right, subRoot->right);

        return left && right;
    }
    */

    /* ch
    atgpt merkle
     bool isSubtree(TreeNode *root, TreeNode *subRoot)
     {
         unordered_map<TreeNode *, string> hashMap;

         string target = computeHash(subRoot);
         cout << "target: " << target << endl;
         computeHash(root, hashMap);

         for (const auto &pair : hashMap)
         {
             if (pair.second == target)
                 return true;
         }
         return false;
     }

     string computeHash(TreeNode *subRoot)
     {
         if (!subRoot)
             return "#";

         string left = computeHash(subRoot->left);
         string right = computeHash(subRoot->right);

         return to_string(subRoot->val) + "," + left + "," + right;
     }

     string computeHash(TreeNode *root, unordered_map<TreeNode *, string> &hashMap)
     {
         if (!root)
             return "#";

         string left = computeHash(root->left, hashMap);
         string right = computeHash(root->right, hashMap);
         string nodehash = to_string(root->val) + "," + left + "," + right;
         hashMap[root] = nodehash;
         cout << root->val << ": " << nodehash << endl;


         return nodehash;
     }
     */
    void postOrderHelper(TreeNode *root, string &hashStr)
    {

        // If the current node is null, append 'L' to indicate a null node
        if (root == nullptr)
        {
            hashStr += 'L';
            return;
        }

        // Use ',' to separate the nodes
        hashStr += "," + to_string(root->val);

        postOrderHelper(root->left, hashStr);
        postOrderHelper(root->right, hashStr);

        // After traversing both subtrees, append '#' to indicate the end of a subtree
        hashStr += '#';
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string mainTree, subTree;

        // generating hashes
        postOrderHelper(root, mainTree);
        postOrderHelper(subRoot, subTree);

        cout << "subRoot: " << subTree << endl;
        cout << "root: " << mainTree << endl;

        return mainTree.find(subTree) != string::npos;
    }
};

int main()
{
    TreeNode *root = createBinaryTree({3, 4, 5, 1, 2});
    TreeNode *subRoot = createBinaryTree({4, 1, 2});
    // TreeNode *root = createBinaryTree({3, 4, 5, 1, 2, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 0});
    // TreeNode *subRoot = createBinaryTree({4, 1, 2});
    // TreeNode *root = createBinaryTree({1, 1});
    // TreeNode *subRoot = createBinaryTree({1});
    // TreeNode *root = createBinaryTree({4, 1, NULL_NODE, NULL_NODE, 2});
    // TreeNode *subRoot = createBinaryTree({1, NULL_NODE, 4, 2});

    Solution sol;

    cout << boolalpha << sol.isSubtree(root, subRoot) << endl;

    return 0;
}