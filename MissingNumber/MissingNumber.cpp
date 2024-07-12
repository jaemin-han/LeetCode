#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
    }
};

int main()
{
    Solution sol;

    vector<int> nums{3, 0, 1};
    // vector<int> nums{0,1};
    // vector<int> nums{9,6,4,2,3,5,7,0,1};

    cout << sol.missingNumber(nums) << endl;

    return 0;
}