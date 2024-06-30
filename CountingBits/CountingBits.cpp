#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
            return {0};

        if (n == 1)
            return {0, 1};

        int i = 2;
        int square2 = 2;
        int count = 0;
        vector<int> ans(n + 1);
        ans[1] = 1;
        while (i <= n)
        {
            ans[i] = ans[count] + 1;
            count++;
            i++;

            if (count == square2)
            {
                count = 0;
                square2 *= 2;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    auto ans = sol.countBits(10);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    return 0;
}