/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLength(struct ListNode* head) 
{
    int length = 0;
    while (head) 
    {
        ++length;
        head = head->next;
    }
    return length;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int len = 0;//总长度
    int i = 0;
    len = getLength(head);
    struct ListNode* Temp = NULL;
    Temp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    //struct ListNode* Temp = malloc(sizeof(struct ListNode));  与上面的等效，创建结点
    Temp->val = 0;
    Temp->next = head; //新创建的结点的下一个结点是头结点

    struct ListNode* L = Temp; //定义一个结构体指针指向该链表

    for(i = 1;i < (len - n + 1);i++)
    {
        L = L->next;
    }
    L->next = L->next->next;
    struct ListNode* ans = Temp->next; //返回原本的链表结构
    free(Temp);
    return ans;
}