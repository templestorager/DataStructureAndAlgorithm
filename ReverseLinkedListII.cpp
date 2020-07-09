// Problem Description
/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

// The key point is to use a dummy node to facilitate the handling of the first node
// and remember the prev node before the mth_node (i.e., the (m-1)th node )
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1), *prev = &dummy;
        dummy.next = head;
        for ( int i = 0; i < m - 1; i++ )
            prev = prev->next;
        ListNode *tail = prev->next; 
        for ( int i = m; i < n; i++ )
        {
            ListNode *cur = tail->next;
            tail->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        
        return dummy.next;
    }
};