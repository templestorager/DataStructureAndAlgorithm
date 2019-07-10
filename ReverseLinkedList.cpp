// Problem Description 
/*
 * Reverse a singly linked list.
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 */

// This is the iterative approach. What it does is insert every node to the head of the list 
// O(n), O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while ( head ) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;
    }
};

// This solution is the recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr ) 
            return head;
        ListNode * next = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }
};