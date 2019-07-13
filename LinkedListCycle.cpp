// Problem Description 
/*
 * Given a linked list, determine if it has a cycle in it.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which represents the 
 * position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is 
 * no cycle in the linked list.
 * 
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * 
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 */

// This solution uses two pointers to traverse the list. 
// if it has a cycle, then the pointers must meet 
// O(N), O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while ( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( fast == slow ) 
                return true;
        }
        return false;
    }
};

// This solution use hash map. 
// As we visit each node, we add it to the tabel and if it happened before, meaning revisit, 
// then it must have a cycle. 
// O(N), O(N)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> visitmap;
        while ( head ) {
            if ( visitmap.find(head) != visitmap.end() ) 
                return true;
            visitmap[head] = true;
            head = head->next;
        }
        return false;
    }
};

