#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left_index = 0;
        int mid_index;
        int right_index = nums.size() - 1;

        while (left_index <= right_index)
        {
            mid_index = left_index + (right_index - left_index) / 2;

            if (nums[mid_index] == target)
                return mid_index;

            if (nums[left_index] <= nums[mid_index])
            {
                if (nums[left_index] <= target && target < nums[mid_index])
                    right_index = mid_index - 1;
                else
                    left_index = mid_index + 1;
            }
            // nums[left_index] > nums[mid_index] 즉 nums[mid_index] < nums[right_index]
            else
            {
                if (nums[mid_index] < target && target <= nums[right_index])
                    left_index = mid_index + 1;
                else
                    right_index = mid_index - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums({4, 5, 6, 7, 0, 1, 2});
    int target = 0;

    // vector<int> nums({4,5,6,7,0,1,2});
    // int target = 3;

    // vector<int> nums({6,7,8,0,1,2,3,4,5});
    // int target = 6;

    // vector<int> nums({3, 1});
    // int target = 1;

    Solution sol;

    cout << sol.search(nums, target) << endl;

    return 0;
}