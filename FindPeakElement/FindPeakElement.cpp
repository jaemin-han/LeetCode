#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left_index, right_index, middle_index;
        left_index = 0;
        right_index = nums.size() - 1;

        while (left_index <= right_index)
        {
            middle_index = (left_index + right_index) / 2;
            if (IsPeakElement(middle_index, nums))
            {
                return middle_index;
            }

            int left_value = (middle_index > 0) ? nums[middle_index - 1] : numeric_limits<int>::min();
            int right_value = (middle_index < nums.size() - 1) ? nums[middle_index + 1] : numeric_limits<int>::min();

            if (left_value >= right_value)
            {
                right_index = middle_index - 1;
            }
            else
            {
                left_index = middle_index + 1;
            }
        }

        // 문제의 조건 상 이 코드는 실행되지 않음
        return 0;
    }

    bool IsPeakElement(int index, vector<int> &nums)
    {
        int left_value = index == 0 ? numeric_limits<int>::min() : nums[index - 1];
        int right_value = index == nums.size() - 1 ? numeric_limits<int>::min() : nums[index + 1];
        int middle_value = nums[index];
        return left_value < middle_value && middle_value > right_value;
    }
};

int main()
{
    // vector<int> nums({1, 2, 3, 1});
    // vector<int> nums({1, 2, 1, 3, 5, 6, 4});
    vector<int> nums({numeric_limits<int>::min()});

    cout << nums[0] << endl;

    Solution sol;

    cout << sol.findPeakElement(nums) << endl;
    return 0;
}