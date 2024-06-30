#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int plus_ = 0;
        // find
        for (; plus_ < nums.size() && nums[plus_] < 0; plus_++)
            ;
        int minus_ = plus_;
        minus_--;

        vector<int> ans(nums.size());
        int i = 0;

        while (true)
        {
            if (minus_ == -1 && plus_ == nums.size())
                break;

            if (minus_ == -1)
            {
                ans[i] = nums[plus_] * nums[plus_];
                plus_++;
                i++;
                continue;
            }

            if (plus_ == nums.size())
            {
                ans[i] = nums[minus_] * nums[minus_];
                minus_--;
                i++;
                continue;
            }

            int minus_square = nums[minus_] * nums[minus_];
            int plus_square = nums[plus_] * nums[plus_];

            if (minus_square <= plus_square)
            {
                ans[i] = minus_square;
                i++;
                minus_--;
            }
            else
            {
                ans[i] = plus_square;
                i++;
                plus_++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums{-4, -1, 0, 3, 10};
    // vector<int> nums{-7, -3, 2, 3, 11};

    auto ans = sol.sortedSquares(nums);

    for (const int num : ans)
        cout << num << " ";

    return 0;
}