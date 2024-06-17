#include "../myHeaders/LinkedList.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;

        while (temp && temp->next)
        {
            if (temp->val == temp->next->val)
            {
                ListNode *del_node = temp->next;
                temp->next = temp->next->next;
                delete del_node;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    // ListNode *node = makeListNode({1, 1, 2});
    ListNode *node = makeListNode({1, 1, 2, 3, 3});
    // ListNode *node = makeListNode({1, 2});

    Solution sol;

    printListNode(sol.deleteDuplicates(node));
}