// Problem Description
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
*/

// Introducing the random pointer in each node causes cycles/loops on the linked list. 
// We address this by traversing the linked list twice. 
// In the first traversal, we just traverse it following the next pointer without considering the random pointer, so it's just copy a singly linked list
// for each node, we create a new node containing the same value. In order to correctly reestablish the random pointer relationship 
// we need to maintain the one-on-one relationship between the old node and the newly created node. 
// In the second traversal, we establish the random pointer relation ship using the mapping. 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( head == nullptr )
            return nullptr;
        Node *reshead = new Node(head->val);
        unordered_map<Node*, Node*> m;
        m[head] = reshead;
        Node *tail = reshead, *cur = head->next;
        // establish the next relationship
        while ( cur )
        {
            tail->next = new Node(cur->val);
            m[cur] = tail->next;
            tail = tail->next;
            cur = cur->next;
        }
        // establish the random relationship
        tail = reshead;
        cur = head;
        while ( cur )
        {
            tail->random = m[cur->random];
            tail = tail->next;
            cur = cur->next;
        }
        
        return reshead;
    }
};

// We can also use recursion to construct the list. We main the relationship like the previous method. 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        return helper( head, m );
    }
    
    Node *helper( Node *head, unordered_map<Node *, Node *> &m )
    {
        if ( !head )
            return nullptr;
        if ( m.count(head) )
            return m[head];
        Node *newhead = new Node(head->val);
        m[head] = newhead;
        newhead->next = helper(head->next, m);
        newhead->random = helper(head->random,m);
        return newhead;
    }
};

// If we are required to not use extra space for the mapping, we could use this following method, which have three steps 
// 1. Clone each of the nodes following the next relatioship 
// 2. Establish the random pointer relationship 
// 3. Sparate the new list from the old list 
// O(n), O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( !head ) 
            return nullptr;
        Node *cur = head;

        // clone the nodes following the next relationship
        while ( cur )
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        
        // establish the random relationship 
        cur = head;
        while ( cur )
        {
            if ( cur->random )
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        // break the new list from the old list 
        cur = head;
        Node *res = head->next;
        while ( cur )
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            if ( tmp->next )
                tmp->next = cur->next->next;
            cur = cur->next;
        }
        
        return res;
    }
    
};