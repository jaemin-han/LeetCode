#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursively
class Solution
{
public:
    ListNode *reverseList(ListNode *node, ListNode *next)
    {
        if (!next)
            return node;
        ListNode *temp = next->next;
        next->next = node;
        return reverseList(next, temp);
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *next = head->next;
        head->next = nullptr;
        return reverseList(head, next);
    }
};
// iteratively
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head || !head->next)
//             return head;
//         if (!head->next->next)
//         {
//             ListNode *temp = head->next;
//             temp->next = head;
//             head->next = nullptr;
//             return temp;
//         }
//         ListNode *before, *current, *after;
//         before = head;
//         current = head->next;
//         after = head->next->next;

//         before->next = nullptr;
//         while (true)
//         {
//             current->next = before;
//             if (!after)
//                 break;
//             before = current;
//             current = after;
//             after = after->next;
//         }
//         return current;
//     }
// };