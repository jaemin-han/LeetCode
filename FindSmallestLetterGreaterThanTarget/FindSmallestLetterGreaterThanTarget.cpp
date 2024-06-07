#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0;
        int right = letters.size() - 1;
        int mid = (left + right) / 2;

        if (letters.back() < target)
            return letters[0];

        while (left <= right)
        {

            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }

        return letters[left];
    }
};

int main()
{
    Solution solution;

    vector<char> letters0 = {'a', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
    char target0 = 'c';
    cout << "Next greatest letter after " << target0 << " is " << solution.nextGreatestLetter(letters0, target0) << endl;

    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << "Next greatest letter after " << target1 << " is " << solution.nextGreatestLetter(letters1, target1) << endl;

    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << "Next greatest letter after " << target2 << " is " << solution.nextGreatestLetter(letters2, target2) << endl;

    vector<char> letters3 = {'x', 'x', 'y', 'y'};
    char target3 = 'z';
    cout << "Next greatest letter after " << target3 << " is " << solution.nextGreatestLetter(letters3, target3) << endl;

    return 0;
}