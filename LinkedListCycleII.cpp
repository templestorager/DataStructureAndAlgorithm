// Problem Description 
/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * To represent a cycle in the given linked list, we use an integer pos which represents the 
 * position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no 
 * cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Follow-up:
Can you solve it without using extra space?
 * 
 */

// Use the set data structure 
// O(n),O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<long> seen;
        while ( head != NULL ) {
            if ( seen.count((long)head) ) 
                return head;
            seen.insert((long)head);
            head = head->next;
        }
        
        return NULL;
    }
};

// This solution is called Tortoise and Hare and it involes two phases 
// Phase I: find the two intersection node (if a cycle exists) 
//          move hare at 2X and tortoise at X speed. 
// Phase II: move starting from the intersection and the begining of the list, they must meet at the 
//          entrance 
// Suppose F is the outside length and the intersection is at a, and (a+b) is the cycle size. 
// From Phase I, we have 2*(F+a) = F+a+b+a, i.e., F = b, which are the moving distances of the 
// two pointers in Phase II. 
// Note that if F is a multipe of cycle size, the analysis still applies with minor changes in thinking 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while ( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast )
                break;
        }
        
        if ( !fast || !fast->next )
            return NULL;
        slow = head;
        while ( slow != fast ) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};