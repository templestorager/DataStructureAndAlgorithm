// Problem Description
/*
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        while( head )
        {
            ListNode *prev = &dummy, *cur = dummy.next;
            ListNode *next = head->next;
            while ( cur && cur->val < head->val )
            {
                prev = cur;
                cur = cur->next;
            }
            
            head->next = cur;
            prev->next = head;
            head = next;
        }
        
        return dummy.next;
    }
};