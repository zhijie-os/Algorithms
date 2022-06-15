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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;

         // 2n = O(n)
        // slow is around half
        while(fast&&fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        // reverse the last half
        ListNode *reversed = reverse(slow);

        // compare
        while(reversed&&head)
        {
            if(reversed->val!=head->val)
            {
                return false;
            }
            reversed=reversed->next;
            head=head->next;
        }

        return true;
    }


    ListNode* reverse(ListNode* head)
    {
        ListNode *prev=nullptr, *curr=head, *next=nullptr;

        while(curr&&curr->next)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

        }

        return prev;
    }
};