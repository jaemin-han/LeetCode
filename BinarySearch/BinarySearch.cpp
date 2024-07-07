#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int now = (start + end) / 2;

            if (nums[now] == target)
                return now;
            else if (nums[now] < target)
                start = now + 1;
            else
                end = now - 1;
        }
        return -1;
    }
};

int main()
{
    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // int target = 9;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;

    Solution sol;

    cout << sol.search(nums, target) << endl;

    return 0;
}