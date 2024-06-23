#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                swap(nums[i - count], nums[i]);
            else
                count++;
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    // vector<int> nums = {0};

    Solution sol;
    sol.moveZeroes(nums);
    for (const int &i : nums)
        cout << i << " ";
    cout << endl;
}