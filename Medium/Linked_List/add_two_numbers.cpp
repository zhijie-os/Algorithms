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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sentinel(0);
        ListNode* d = &sentinel;
        

        int sum = 0;
        while(l1||l2)
        {
            sum/= 10;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            d->next = new ListNode(sum%10);
            d=d->next;
        }

        if(sum/10>0)
            d->next = new ListNode(1);
        return sentinel.next;
    }
};