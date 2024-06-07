#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate;
        for (const int &i : nums)
        {
            if (count == 0)
            {
                candidate = i;
                count++;
            }
            else if (candidate == i)
                count++;
            else
                count--;
        }
        return candidate;
    }
};

int main()
{
    vector<int> nums;
    nums = {3, 2, 3};
    // nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;

    cout << sol.majorityElement(nums) << endl;
}