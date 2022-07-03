/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;

        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode *ptr1, *ptr2;
        ptr1 = head;
        dummy1->next = head;

        ptr2= head->next;
        dummy2->next = head->next;



        while(ptr1&&ptr1->next&&ptr1->next->next||ptr2&&ptr2->next&&ptr2->next->next)
        {
            if(ptr1)
            {
                ptr1->next = ptr1->next->next;
                ptr1 = ptr1->next;
            }
            if(ptr2)
            {
                ptr2->next = ptr2->next->next;
                ptr2 = ptr2->next;
            }
        }
        ptr1->next = dummy2->next;
        return dummy1->next;
    }
};