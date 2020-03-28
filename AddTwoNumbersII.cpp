// Problem Description
/*
 You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

// Idea: since the list contains reversed position, we use stack to access reversed positions 
//  To faciliate linked list insert, we use a dummy head. 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode DummyHead(0);
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int sum, carry = 0;
        while ( !s1.empty() || !s2.empty() )
        {
            sum = 0;
            if ( !s1.empty() )
            {
                sum += s1.top();
                s1.pop();
            }
            if ( !s2.empty() )
            {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            ListNode *tmp = new ListNode(sum%10);
            tmp->next = DummyHead.next;
            DummyHead.next = tmp;
            carry = sum / 10;
        }
        
        if ( carry )
        {
            ListNode *tmp = new ListNode(carry);
            tmp->next = DummyHead.next;
            DummyHead.next = tmp;
        }
        
        return DummyHead.next;
    }
};