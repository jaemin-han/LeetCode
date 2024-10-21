#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        queue<int> buffer;
        int sum = 0;
        int maxSum;

        for (int i = 0; i < k; ++i)
        {
            buffer.push(nums[i]);
            sum += nums[i];
        }

        int temp;
        maxSum = sum;

        for (int i = k; i < nums.size(); ++i)
        {
            buffer.push(nums[i]);
            temp = buffer.front();
            buffer.pop();

            sum = sum + nums[i] - temp;
            maxSum = max(maxSum, sum);
        }
        return double(maxSum) / k;
    }
};

int main()
{
    vector<int> nums{1, 12, -5, -6, 50, 3};
    int k = 4;

    Solution sol;

    cout << sol.findMaxAverage(nums, k) << endl;
}