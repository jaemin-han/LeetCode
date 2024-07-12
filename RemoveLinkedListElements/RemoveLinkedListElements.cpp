#include "../myHeaders/LinkedList.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    // ListNode *removeElements(ListNode *head, int val)
    // {
    //     if (!head)
    //         return head;

    //     ListNode *bef, *cur;
    //     bef = nullptr;

    //     cur = head;
    //     while (cur)
    //     {
    //         if (cur->val == val)
    //         {
    //             if (cur == head)
    //             {
    //                 head = head->next;
    //                 delete cur;
    //                 cur = head;
    //             }
    //             else
    //             {
    //                 bef->next = cur->next;
    //                 delete cur;
    //                 cur = bef->next;
    //             }
    //         }
    //         else
    //         {
    //             bef = cur;
    //             cur = cur->next;
    //         }
    //     }
    //     return head;
    // }

    // Recursive version
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            auto *temp = head->next;
            delete head;
            head = temp;
        }
        if (head)
            head->next = removeElements(head->next, val);

        return head;
    }
};
int main()
{
    vector<int> nums{1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    // vector<int> nums{1, 1, 7, 7, 7};
    // int val = 7;

    ListNode *head = makeListNode(nums);

    Solution sol;

    auto *ans = sol.removeElements(head, val);

    printListNode(ans);

    return 0;
}