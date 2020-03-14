// Problem Description
/*
 
 Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Using a dummy head would much simplify handling corner cases 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy, *tail = &dummy, *cur = head;
        ListNode HeadReleaseDummy, *ReleaseWalk = &HeadReleaseDummy;
        while ( cur  ) 
        {
            if ( cur->val != val ) 
            {
                tail->next = cur;
                tail = tail->next;
            }
            else
            {
                ReleaseWalk->next = cur;
                ReleaseWalk = ReleaseWalk->next;
            }
            cur = cur->next;
        }
        tail->next = NULL;  // import to end the linked list 
        ReleaseWalk->next = NULL;
    
        while ( HeadReleaseDummy.next )
        {
            ReleaseWalk = HeadReleaseDummy.next;
            HeadReleaseDummy.next = HeadReleaseDummy.next->next;
            delete ReleaseWalk;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy, *pre = &dummy;
        dummy.next = head;
        while ( pre->next )
        {
            if ( pre->next->val == val )
            {
                ListNode *tmp = pre->next;
                pre->next = tmp->next;
                tmp->next = NULL;
                delete tmp;
            }
            else
            {
                pre = pre->next;
            }
        }
        
        return dummy.next;
    }
};

// Recursive 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if ( !head )
            return NULL;
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next : head;
    }
};