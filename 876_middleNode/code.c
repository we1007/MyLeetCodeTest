/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /*
 解法分析：快慢指针，当走的快的指针走到末端时，慢的指针刚好到中间位置
 */
 
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* pSlow = head;
    struct ListNode* pFast = head;
    while (pFast != NULL && pFast->next != NULL) 
    {
        pSlow = pSlow->next;
        pSlow = pFast->next->next;
    }
    return pSlow;
}