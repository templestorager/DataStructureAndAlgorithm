// Problem Description 
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

// We can use recursion to recursively reverse the nodes in K groups. 
// the reverse function takes the head and the (k+1)th nodes as its arguments and reverses the k nodes 
// not including the last one.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for ( int i = 0; i < k; i++ )
        {
            if ( !cur )
                return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head,cur);
        head->next = reverseKGroup(cur,k);
        return new_head;
    }
    
    ListNode *reverse( ListNode * s, ListNode * e )
    {
        ListNode * pre = e;
        while ( s != e )
        {
            ListNode *next = s->next;
            s->next = pre;
            pre = s;
            s = next;
        }
        
        return pre;
    }
};

// We can also use an iterative method to reverse every k nodes 
// The main point is to first link all the nodes together.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *prev = &dummy, *cur = prev;
        int nodes = 0;
        dummy.next = head;
        while ( (cur = cur->next) ) 
            nodes++;
        while ( nodes >= k )
        {
            cur = prev->next;
            for ( int i = 1; i < k; i++ )
            {
                ListNode *next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = cur;
            nodes -= k;
        }
        
        return dummy.next;
    }
};