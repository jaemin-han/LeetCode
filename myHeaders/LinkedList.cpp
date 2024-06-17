#include "LinkedList.h"
#include <iostream>

using namespace std;

ListNode *makeListNode(vector<int> nums)
{
    if (nums.empty())
        return nullptr;

    ListNode *temp = new ListNode(nums[0]);
    ListNode *cur = temp;

    for (size_t i = 1; i < nums.size(); i++)
    {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return temp;
}

void printListNode(ListNode *node)
{
    while (node)
    {
        cout << node->val;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}