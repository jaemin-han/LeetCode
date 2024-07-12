#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != m * n)
            return {};

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result[i][j] = original[n * i + j];
        return result;
    }
};

int main()
{
    // vector<int> original{1, 2, 3, 4};
    // int m = 2;
    // int n = 2;
    vector<int> original{1, 1, 1, 1};
    int m = 4;
    int n = 1;

    Solution sol;

    auto result = sol.construct2DArray(original, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}