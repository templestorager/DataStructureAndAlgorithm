// Problem Description 
/*
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * Input: 1->2->2->1
 * Output: true
 * Follow up: Could you do it in O(n) time and O(1) space?
 * 
 */

// This solutin uses an auxiliary stack. it first push all the elements to the stack, 
// as then compare the element from the begining as we traverse and pop 
// O(n), O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head; 
        stack<int> s;
        while( temp ) {
            s.push( temp->val );
            temp = temp->next;
        }
        
        while ( head ) {
            int val = s.top(); 
            s.pop();
            if ( val != head->val ) 
                return false;
            head = head->next;
        }
        
        return true;
    }
};


// This solution uses recursion. 
// As it enters recursion, the innermost call would be the end (null), and when it returns an upper level 
// cur == head (pointing to the first node), node is the previous of the NULL who returns true
// i.e., node is the last node 
// as the stack is rewinded, the node in its updated stack is the previous node, but we need to advance 
// the node from the front, that's why we use reference to change the cur of a rewinded stack 
// O(n), O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        return helper(head,cur);
    }
    
    bool helper(ListNode *node, ListNode *&cur ) {
        if ( node == nullptr )
            return true;
        bool res = helper(node->next,cur) && ( cur->val == node->val);
            cur = cur->next;
        return res;
    }
};

// This solution uses two pointers to find the middle node.
// It pushes the first half values to a stack and compares them with the second half nodes. 
// O(n), O(n)
class Solution {
public:
    bool isPalindrome( ListNode* head ) {
        if ( !head || !head->next ) 
            return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(slow->val);
        while ( fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        // odd number of nodes 
        if ( !fast->next )
            s.pop();
        while ( slow->next ) {
            slow = slow->next;
            if ( s.top() != slow->val )
                return false;
            s.pop();
        }
        
        return true;
    }
};

// Basd on the above solution, instead of using a stack, we reverse the second half nodes 
// so that we can compare them sequentially 
// O(n), O(1)
class Solution {
public:
    bool isPalindrome( ListNode* head ) {
        if ( !head || !head->next )
            return true; 
        ListNode *slow = head, *fast = head;
        while ( fast->next && fast->next->next ) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * last = slow->next, *prev = head;
        while ( last->next ) { 
            ListNode *temp = last->next; 
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp; 
        }
        
        // both odd and even numbers of nodes are covered here
        // if odd number the middle value would not be compared...
        while ( slow->next ) {
            slow = slow->next;
            if ( slow->val != prev->val ) 
                return false;
            prev = prev->next;
        }
        
        return true;
    }
};