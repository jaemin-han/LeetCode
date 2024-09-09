#include <iostream>
#include "../myHeaders/LinkedList.h"

class Solution
{
public:
    // two pointer
    // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    // {
    //     ListNode *mergedHead;

    //     if (list1 && list2)
    //     {
    //         if (list1->val <= list2->val)
    //         {
    //             mergedHead = list1;
    //             list1 = list1->next;
    //         }
    //         else
    //         {
    //             mergedHead = list2;
    //             list2 = list2->next;
    //         }
    //     }
    //     else if (list1)
    //         return list1;
    //     else
    //         return list2;

    //     ListNode *curNode = mergedHead;

    //     while (list1 && list2)
    //     {
    //         if (list1->val <= list2->val)
    //         {
    //             curNode->next = list1;
    //             curNode = curNode->next;
    //             list1 = list1->next;
    //         }
    //         else
    //         {
    //             curNode->next = list2;
    //             curNode = curNode->next;
    //             list2 = list2->next;
    //         }
    //     }

    //     if (list1)
    //         curNode->next = list1;
    //     else
    //         curNode->next = list2;

    //     return mergedHead;
    // }

    // recursion
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *mergedHead;

        if (list1->val <= list2->val)
        {
            mergedHead = list1;
            list1 = list1->next;
        }
        else
        {
            mergedHead = list2;
            list2 = list2->next;
        }
        

        mergedHead->next = mergeTwoLists(list1, list2);
        return mergedHead;
    }
};

int main()
{
    auto *list1 = makeListNode({1, 2, 4});
    auto *list2 = makeListNode({1, 3, 4});
    // auto* list1 = makeListNode({});
    // auto* list2 = makeListNode({});
    // auto* list1 = makeListNode({});
    // auto* list2 = makeListNode({0});

    Solution sol;

    printListNode(sol.mergeTwoLists(list1, list2));
}