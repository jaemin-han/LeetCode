#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     int profit = 0;
    //     int low = prices[0];

    //     for (int price : prices)
    //     {
    //         if (price > low)
    //             profit = max(profit, price - low);
    //         else
    //             low = price;
    //     }
    //     return profit;
    // }

    // Dynamic Programming
    int maxProfit(vector<int> &prices)
    {
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }

        return max_profit;
    }
};

int main()
{

    vector<int> prices{7, 1, 5, 3, 6, 4};
    // vector<int> prices{7, 6, 4, 3, 1};

    Solution sol;

    cout << sol.maxProfit(prices) << endl;

    return 0;
}