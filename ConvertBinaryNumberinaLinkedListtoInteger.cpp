// Problem Description
/*
 Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

  Return the decimal value of the number in the linked list.
 */

// We can just process in order and shift 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while ( head ) 
        {
            res = res << 1 | head->val;
            head = head->next;    
        }
        
        return res;
    }
};

// basically we need to process the nodes in a reverse order.
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int i = 0, shift = 0, res = 0;
        ListNode * Arr[30];
        while ( head )
        {
            Arr[i++] = head;
            head = head->next;
        }
        i--;
        while ( i >= 0 )
        {
            if ( Arr[i]->val )
                res |= Arr[i]->val << shift;
            shift++;
            i--;
        }
        
        return res;
    }
};
