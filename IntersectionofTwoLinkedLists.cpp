// Problem Description 
/*
 * 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *  (1). Brute force: O(mn), O(1)
 *  (2). Using a hash table to store one list, and check the other one. The first encountered 
 *       node in the hast table is the intersection node.  O(m+n), O(m) or O(n)
 *  (3).  Using two pointers. Say the lists has A + C and B + C length respectively. 
 *        if we have switched each of them once and if there is indeed an intersection, then they must 
 *        meet at the intersection node and till then each list has traversed A+B+C distance. 
 *        O(m+n), O(1)
 */

// Approach (2)
class Solution {
public:
    ListNode *getIntersectionNode( ListNode *headA, ListNode *headB ) {
        unordered_set<ListNode *> s; 

        while ( headA )  {
            s.insert( headA );
            headA = headA->next;
        }
        
        while ( headB ) { 
            if ( s.find( headB ) != s.end() ) 
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

// Approach (3)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        while ( tempA != tempB  ) {
            tempA = tempA ? tempA->next : headB;
            tempB = tempB ? tempB->next : headA;
        }
        
        return tempA;
    }
};



