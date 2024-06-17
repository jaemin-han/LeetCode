#include "../myHeaders/LinkedList.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *rev = nullptr;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            rev = slow;
            slow = slow->next;
            rev->next = prev;
            prev = rev;
        }

        if (fast)
            slow = slow->next;

        while (slow && slow->val == rev->val)
        {
            slow = slow->next;
            rev = rev->next;
        }

        return !rev;
    }
};

int main()
{
    vector<int> nums = {1};
    ListNode *node = makeListNode(nums);
    printListNode(node);

    Solution sol;
    cout << boolalpha << sol.isPalindrome(node) << endl;
}