#include <iostream>
#include <unordered_map>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (!fast || !fast->next)
        {
            cout << "slow: " << slow->val << " fast: " << fast->val << endl;
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};