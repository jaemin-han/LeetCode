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
            if (count == 0)
                sum = 0;

            auto curPair = myQueue.front();
            myQueue.pop();

            if (curPair. && )

            
        }
    }
};

int main()
{

    auto *root = createBinaryTree({3, 9, 20, NULL_NODE, NULL_NODE, 15, 7});
    // auto* root = createBinaryTree({3,9,20,15,7});

    Solution sol;

    for (auto d : sol.averageOfLevels(root))
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}