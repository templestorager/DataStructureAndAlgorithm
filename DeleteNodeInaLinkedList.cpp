// Problem Description 
/*
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
    Example 1:

    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
    Example 2:

    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
    

    Note:

    The linked list will have at least two elements.
    All of the nodes' values will be unique.
    The given node will not be the tail and it will always be a valid node of the linked list.
    Do not return anything from your function.
 */

 // The tricky part it that we are not given the head of the linked list. As a result, we 
 // cann't obtain the previous node of the given node to be deleted.
 //  The tactic is to replace the node with the node (content) and then delete the next node. 
 // Note this method works because it's said the given node is not the tail.

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next;
        node->next = tmp->next;
        node->val = tmp->val;
        delete tmp;
    }
};