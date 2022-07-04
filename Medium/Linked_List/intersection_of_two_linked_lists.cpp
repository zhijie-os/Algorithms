/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// brute force = O(mn)
class Solution {
public:

    // thoughts: 
    // O(n) to reverse a linked list
    // O(n+m) to reverse both
    // walk back k times to find the first one that differs

    // O(n) to count len
    // O(n+m) to count both linkedlists' length
    


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        int lenA=0, lenB=0;
        while(ptr1||ptr2)
        {
            if(ptr1)
            {
                lenA++;
                ptr1 = ptr1->next;
            }
            if(ptr2)
            {
                lenB++;
                ptr2 = ptr2->next;
            }
        }


        
        int diff;
        if(lenA > lenB)
        {
            diff = lenA - lenB;
            ptr1 = headA, ptr2 = headB;
        }
        else 
        {
            diff = lenB - lenA;
            ptr1 = headB, ptr2 = headA;
        }

        for(int i=0; i<diff;i++)
        {
            ptr1 = ptr1->next;
        }

        while(ptr1&&ptr2&&ptr1!=ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;            
        }


        return ptr1;        

    }
};