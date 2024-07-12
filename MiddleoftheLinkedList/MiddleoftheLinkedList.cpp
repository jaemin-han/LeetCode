#include "../myHeaders/LinkedList.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (true)
        {
            if (fast->next && fast->next->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else if (fast->next)
            {
                slow = slow->next;
                return slow;
            }
            else
            {
                return slow;
            }
        }
    }
};

int main()
{
    // auto *head = makeListNode({1, 2, 3, 4, 5});
    // auto *head = makeListNode({1, 2, 3, 4, 5, 6});
    // auto *head = makeListNode({1, 2});
    auto *head = makeListNode({1});

    Solution sol;

    cout << sol.middleNode(head)->val << endl;

    return 0;
}