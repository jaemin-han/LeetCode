#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
    }
};

int main()
{
    vector<int> nums({2, 5, 6, 0, 0, 1, 2});
    int target = 0;

    // vector<int> nums({2, 5, 6, 0, 0, 1, 2});
    // int target = 3;

    Solution sol;

    cout << sol.search(nums, target) << endl;
}
