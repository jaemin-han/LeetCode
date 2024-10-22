#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex, rightIndex;

        leftIndex = 0;
        rightIndex = height.size() - 1;

        int maxArea = 0;

        while (leftIndex < rightIndex)
        {
            int curArea = (rightIndex - leftIndex) * min(height[leftIndex], height[rightIndex]);
            maxArea = maxArea < curArea ? curArea : maxArea;

            height[leftIndex] < height[rightIndex] ? leftIndex++ : rightIndex--; 
        }
        return maxArea;
    }
};

int main()
{
    // vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {1, 1};

    Solution sol;

    cout << sol.maxArea(height) << endl;
    
    return 0;
}