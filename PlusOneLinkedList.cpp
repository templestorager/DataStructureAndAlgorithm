// Problem Description
/*

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]
*/

// Idea: find the right-most non-nine number, increase the number by 1 and change all the following 9s to zero
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *non_nine; 
        head = dummyhead;
        while ( head )
        {
            if ( head->val != 9 )
            {
                non_nine = head;
            }
            head = head->next;
        }
        non_nine->val++;        // increase one to the right-most non-nine
        non_nine = non_nine->next; // point to the first nine after the non-nine, change all nine to zero 
        while( non_nine )
        {
            non_nine->val = 0;
            non_nine = non_nine->next;
        }
        return dummyhead->val ? dummyhead : dummyhead->next;  // if the increase to the dummyhead, meaning the most significant bit is nine
    }
};

// Idea: we first reverse the list so we can add one from the head of the list. after the addition, we 
// need reverse it again.
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if ( !head )
            return head;
        ListNode *reverse_head = reverseList(head), *walk = reverse_head, *tail;
        int carry = 1;      // initial 1 to be added 
        while(walk)
        {
            int sum = walk->val + carry;
            if ( sum < 10 )
            {
                walk->val = sum;
                carry = 0;
                break;
            }
            else
            {
                walk->val = sum % 10;
                carry = sum / 10;
            }
            tail = walk;            // point to the last node in case a final carry one is generated 
            walk = walk->next;
        }
        
        if ( carry )
        {
            ListNode *lastnode = new ListNode(carry);
            tail->next = lastnode;
        }
        return reverseList(reverse_head);
    }
    
private:
    ListNode *reverseList(ListNode *head )
    {
        ListNode dummyhead = ListNode(-1);
        if ( !head ) 
            return head;
        while( head )
        {
            ListNode *next = head->next;
            head->next = dummyhead.next;
            dummyhead.next = head;
            head = next;
        }     
        return dummyhead.next; 
    }
};

// This method leverage the recursive natrue of recursion to do the addition at the end of the linked list first
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if ( !head )
            return head;
        int carry = helper(head);
        if ( carry )
        {
            ListNode *new_head = new ListNode(carry);
            new_head->next = head;
            return new_head;
        }
        return head;
    }
    
    int helper( ListNode *node )
    {
        if ( !node ) 
            return 1;
        int carry = helper(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};

// Idea: this method leverages a stack to revese the list. The advantage is that it maintains the original list
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        if ( !head ) 
            return head;
        ListNode *walk = head;
        while( walk )
        {
            s.push(walk);
            walk = walk->next;
        }
        
        int sum = 0, carry = 1;
        while ( !s.empty() && carry )
        {
            ListNode *top = s.top();
            s.pop();
            sum = top->val + carry;
            top->val = sum % 10;
            carry = sum / 10;
        }
        
        if ( carry )
        {
            ListNode *last_carry = new ListNode(carry);
            last_carry->next = head;
            head = last_carry;
        }
        
        return head;
    }
};

// Idea: use stack to faciliate finding the first non-nine. 
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        if ( !head ) 
            return head;
        ListNode *walk = head;
        while( walk )
        {
            s.push(walk);
            walk = walk->next;
        }
        
        while ( !s.empty() )
        {
            ListNode *top = s.top();
            s.pop();
            if ( top->val == 9 )
            {
                top->val = 0;
            }
            else 
            {
                top->val++;
                return head;
            }
        }

        ListNode *last_carry = new ListNode(1);
        last_carry->next = head;
        head = last_carry;

        return head;
    }
};