// Problem Description
/*
* Merge two sorted linked lists and return it as a new list. The new list should be 
made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */

// This solution processes a node a time from either of the two sorted lists 
// Time Complexity O(n+m), Space Complexity O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *prev = head;
        while( l1 != nullptr && l2 != nullptr ) {
            if ( l1->val <= l2->val ) {
                prev->next = l1;
                l1 = l1->next;
            } 
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        
        prev->next = l1 ? l1 : l2; 
        return head->next;
    }
};

// this solution transforms it to be a recurrence problem 
// Time complexity O(n+m), Space Complexity O(n+m)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )
            return l2;
        else if ( l2 == nullptr ) 
            return l1;
        else if ( l1->val <= l2->val ) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        } 
        else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};