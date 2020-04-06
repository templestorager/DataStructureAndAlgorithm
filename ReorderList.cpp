// Problem Description
/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

// Idea: count the number of nodes in the list, reverse the right half of the list and merge the two lists
class Solution {
public:
    void reorderList(ListNode* head) {
        if ( !head || !head->next )
        return;
        ListNode *left, *right, *tail, *prev;
        int n = CountList(head);
        left = tail = head;
        for(int i = 0; i < (n+1) / 2; i++ )
        {
            prev = tail;
            tail = tail->next;
        }
        right = tail;
        prev->next = NULL;
        right = reverseList(right);
        while( left && right )
        {
            ListNode *tmp = right->next;
            right->next = left->next;
            left->next = right;
            right = tmp;
            left = left->next->next;
        }

    }
private: 
    int CountList( ListNode * head) 
    {
        int cnt = 0;
        while( head )
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode * reverseList( ListNode *head )
    {
        ListNode dummy(-1);
        while( head )
        {
            ListNode *next = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = next;
        }
        
        return dummy.next;
    }
};