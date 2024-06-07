#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class NumArray
{
public:
    vector<int> *nums;
    vector<int> preSum;

    NumArray(vector<int> &nums)
    {
        this->nums = &nums;
        preSum.resize(nums.size());
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            preSum[i] = nums[i] + preSum[i - 1];
    }

    int sumRange(int left, int right)
    {
        if (left != 0)
            return preSum[right] - preSum[left - 1];
        else
            return preSum[right];
    }
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray numarray(nums);

    cout << numarray.sumRange(0, 2) << endl;
    cout << numarray.sumRange(2, 5) << endl;
    cout << numarray.sumRange(0, 5) << endl;
}