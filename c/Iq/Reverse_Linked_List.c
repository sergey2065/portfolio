#include <stdlib.h>


typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;
 


struct ListNode* reverseList(struct ListNode* head)
{
    ListNode *newHead = NULL;
    if (head == NULL || head-> next == NULL)
    {
        return head;
    }
    newHead = reverseList(head-> next);
    head-> next-> next = head;
    head-> next = NULL;
    return newHead;
}
