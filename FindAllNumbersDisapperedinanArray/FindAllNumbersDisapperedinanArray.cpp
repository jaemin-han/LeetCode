#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> return_vector;
        vector<bool> has_num(nums.size() + 1, false);

        has_num[0] = true;
        for (const int &i : nums)
            has_num[i] = true;

        for (int i = 0; i < has_num.size(); i++)
        {
            if (!has_num[i])
                return_vector.push_back(i);
        }
        return return_vector;
    }
};

int main()
{
    Solution sol;

    // vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    // vector<int> nums({4, 3, 2, 7, 8, 2, 3, 1});

    auto answer = sol.findDisappearedNumbers(nums);

    for (const int &i : answer)
        cout << i << " ";
    cout << endl;
}