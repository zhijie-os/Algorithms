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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slow= &head;
        ListNode* fast = head;
        for(int i=1;i<n;i++)
        {
            fast = fast -> next;
        }

        while(fast->next)
        {
            // this is normal linked list traversal
            slow = &((*slow)->next);
            fast = fast ->next;
        }

        // here is the tricky part
        // the pointer to this point
        *slow = (*slow)->next;
        return head;
    }
};