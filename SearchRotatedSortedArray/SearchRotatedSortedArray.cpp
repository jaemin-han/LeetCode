#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 3)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target)
                    return i;
            }
            return -1;
        }

        int left_index, mid_index, right_index;

        left_index = 0;
        right_index = nums.size() - 1;
        mid_index = nums.size() / 2;

        int left_max;
        // left index 가 더 클 때
        if (nums[mid_index] > nums[mid_index + 1])
        {
            left_max = mid_index;

        }
        else if (nums[left_index] > nums[mid_index])
        {
            // 다음 인덱스보다 큰 인덱스를 찾을 때 까지
            // while (le < mi)
            while (true)
            {
                left_max = (left_index + mid_index) / 2;
                if (nums[left_max] > nums[left_max + 1])
                {
                    break;
                }

                if (nums[left_max] > nums[left_index])
                {
                    left_index = left_max;
                }
                else
                {
                    mid_index = left_max;
                }
            }
        }
        else
        {
            while (true)
            {
                left_max = (mid_index + right_index) / 2;
                if (nums[left_max] > nums[left_max + 1])
                {
                    break;
                }
                if (nums[left_max > nums[right_index]])
                {
                    mid_index = left_max;
                }
                else
                {
                    right_index = left_max;
                }
            }
        }

        if (target > nums[left_max] || target < nums[left_max + 1])
            return -1;

        int left_min = 0;
        int right_min = left_max + 1;
        int right_max = nums.size() - 1;

        while (left_min < left_max)
        {
            mid_index = (left_min + left_max) / 2;
            if (nums[mid_index] == target)
                return mid_index;
            
            if (nums[mid_index] > target)
            {
                left_max = mid_index;
            }
            else
            {
                left_min = mid_index;
            }
        }

        while (right_min < right_max)
        {
            mid_index = (left_min + left_max) / 2;

            if (nums[mid_index] == target)
            {
                return mid_index;
            }

            if (nums[mid_index] > target)
            {
                right_max = mid_index;
            }
            else
            {
                right_min = mid_index;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums({4,5,6,7,0,1,2});
    int target = 0;

    

    // vector<int> nums({4,5,6,7,0,1,2});
    // int target = 3;

    // vector<int> nums({6,7,8,0,1,2,3,4,5});
    // int target = 6;

    Solution sol;

    cout << sol.search(nums, target) << endl;

    return 0;
}