#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
    }
};

int main()
{
    vector<int> vec1 = {1, 2, 3, 1};
    vector<int> vec2 = {1, 2, 3, 4};
    vector<int> vec3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    Solution sol;

    cout << boolalpha << sol.containsDuplicate(vec1) << endl;
    cout << boolalpha << sol.containsDuplicate(vec2) << endl;
    cout << boolalpha << sol.containsDuplicate(vec3) << endl;
}