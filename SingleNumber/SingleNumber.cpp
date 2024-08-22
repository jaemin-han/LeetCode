#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int answer = 0;
        for (int num: nums)
           answer = xor(answer, num);
        return answer;
    }

    int xor(int a, int b)
    {
       return (~(a & b)) & (a | b);
    }
};

int main() 
{
    vector<int> nums{2, 2, 1};
    // vector<int> nums{4, 1, 2, 1, 2};
    // vector<int> nums{1};
    
    Solution sol;

    cout << sol.singleNumber(nums) << endl;
    return 0;
}   