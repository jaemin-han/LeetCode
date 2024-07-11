#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int first = 1;
        int second = 2;
        int result;

        for (int i = 3; i <= n; i++)
        {
            result = first + second;
            if (i == n)
                return result;
            first = second;
            second = result;
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    cout << sol.climbStairs(5) << endl;
    return 0;
}