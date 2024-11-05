#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left_index, right_index, mid_index;
        left_index = 0;
        right_index = nums.size() - 1;

        while (left_index <= right_index)
        {
            mid_index = left_index + (right_index - left_index) / 2;
            if (nums[mid_index] == target)
                return true;

            if (nums[left_index] == nums[mid_index] && nums[mid_index] == nums[right_index])
            {
                left_index++;
                right_index--;
            }
            else if (nums[left_index] <= nums[mid_index])
            {
                if (nums[left_index] <= target && target < nums[mid_index])
                    right_index = mid_index - 1;
                else
                    left_index = mid_index + 1;
            }
            else
            {
                if (nums[mid_index] < target && target <= nums[right_index])
                    left_index = mid_index + 1;
                else
                    right_index = mid_index - 1;
            }
        }
        return false;
    }
};

int main()
{
    // vector<int> nums({2, 5, 6, 0, 0, 1, 2});
    // int target = 0;

    // vector<int> nums({2, 5, 6, 0, 0, 1, 2});
    // int target = 3;

    vector<int> nums({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1});
    int target = 2;

    // nums 에서 2 인 index 를 출력

    Solution sol;

    // bool 을 true, false 로 출력할 수 있게
    cout << boolalpha << sol.search(nums, target) << endl;
}
