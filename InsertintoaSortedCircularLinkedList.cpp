// Problem Description 
/*
Given a node from a Circular Linked List which is sorted in ascending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the original given node.


Example 1:


Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.



Example 2:

Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). We create a new single circular list and return the reference to that single node.
Example 3:

Input: head = [1], insertVal = 0
Output: [1,0]

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

// case 1: the given list is empty, then we just create the list containing the single new node and return the new node
// case 2: the value is between prev and cur, insert it between these two nodes 
// case 3: if prev->val(maximal) > cur->val(minimal), if value is greater than maximal or less than minimal, still insert between pre and cur
// case 4: all nodes have the same value including the case where there is only one node, can also be inserted between prev and cur 
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *prev = nullptr, *cur = nullptr;
        if ( !head ) 
        {
            Node *head = new Node(insertVal);
            head->next = head;
            return head;
        }
        prev = head, cur = head->next;
        bool ToInsert = false;
        do 
        {
            if ( prev->val <= insertVal && insertVal <= cur->val )
                ToInsert = true;
            else if ( prev->val > cur->val )
            {
                if ( insertVal >= prev->val || insertVal <= cur->val )
                    ToInsert = true;
            }
            
            if ( ToInsert )
            {
                prev->next = new Node(insertVal,cur);
                return head;
            }
            prev = cur;
            cur = cur->next;
        } while ( prev != head );
        
        prev->next = new Node(insertVal,cur);
        return head;
    }
};

// More concise writing 
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if ( !head )
        {
            Node *head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node *prev = head, *cur = head->next;
        while ( cur != head )
        {
            if ( prev->val <= insertVal && cur->val >= insertVal ) break;
            if ( (prev->val > cur->val) && (insertVal >= prev->val || insertVal <= cur->val) ) break;
            prev = cur;
            cur = cur->next;
        }
                
        prev->next = new Node(insertVal,cur);
        return head;
    }
};