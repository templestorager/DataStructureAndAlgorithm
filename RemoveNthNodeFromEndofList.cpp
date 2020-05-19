// Problem Description
/*
 Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

// This solution takes two passes. It counts the total number of nodes in the first pass. 
// Then the (len - n + 1)th node is the one need to be deleted. 
// It's always convenient to add a dummmy head when dealing with linked list problems. It saves a lot 
// of trouble dealing with corner cases
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // the nth starting from the end (1-based) is the same as the (len-n)th (0-based)
        ListNode dummy(0);
        int len = 0;
        ListNode *walk = head, *tail = &dummy;
        while ( walk )
        {
            tail->next = walk;
            tail = tail->next;
            walk = walk->next;
            len++;
        }
        
        tail->next = nullptr;
        
        walk = &dummy;
        int i = len - n;
        while ( i-- > 0 )
        {
            walk = walk->next;
        }
        
        ListNode *deletenode = walk->next;
        walk->next = deletenode->next;
        delete deletenode;
        return dummy.next;
    }
};

// This method uses two pointers which are n nodes apart. So when the first (tail) reaches the end, 
// the other pointers is pointing to the node prior to the node to delete. 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // the nth starting from the end (1-based) is the same as the (len-n)th (0-based)
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *tail = &dummy;
        while ( n-- )
        {
            tail = tail->next;
        }
        
        while ( tail->next )
        {
            tail = tail->next;
            prev = prev->next;
        }
        
        ListNode *deletenode = prev->next;
        prev->next = prev->next->next;
        delete deletenode;
        return dummy.next;
    }
};