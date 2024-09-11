#include <iostream>
#include <vector>
#include <queue>
// #include

#include "../myHeaders/TreeNode.h"

using namespace std;

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> myQueue;

        myQueue.push({root, 0});
        int count = 0;
        int curLevel = 0;
        int sum = 0;
        vector<double> answer;

        TreeNode* curNode;

        while (!myQueue.empty())
        {
            auto curPair = myQueue.front();
            myQueue.pop();

            if (curPair.second > curLevel)
            {
                curLevel = curPair.second;
                answer.push_back(double(sum) / count);
                sum = curPair.first->val;
                count = 1;
            }
            else
            {
                sum += curPair.first->val;
                count++;
            }

            if (curPair.first->left)
                myQueue.push({curPair.first->left, curPair.second + 1});

            if (curPair.first->right)
                myQueue.push({curPair.first->right, curPair.second + 1});
        }
        answer.push_back(double(sum) / count);
        return answer;
    }
};

int main()
{

    // auto *root = createBinaryTree({3, 9, 20, NULL_NODE, NULL_NODE, 15, 7});
    // auto* root = createBinaryTree({3,9,20,15,7});
    // auto* root = createBinaryTree({3});
    auto* root = createBinaryTree({2147483647, 2147483647, 2147483647});

    Solution sol;

    for (auto d : sol.averageOfLevels(root))
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}