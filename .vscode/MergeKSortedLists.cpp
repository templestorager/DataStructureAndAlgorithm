// Problem Description 
/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * 
 * Output: 1->1->2->3->4->4->5->6
 * 
 */

// This solution use divid and conquer to merge two lists respectively. 
// O(Nklg(k))
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.empty() )
            return NULL;
        int listnum = lists.size();
        while ( listnum > 1 ) {
            int mid = ( listnum + 1 ) / 2;
            for ( int i = 0; i < listnum / 2; i++ ) {
                lists[i] = merge2Lists(lists[i],lists[mid+i]);
            }
            listnum = mid;
        }
        
        return lists[0];
    }
    
    ListNode  *merge2Lists(ListNode *l1, ListNode *l2 )  {
        ListNode dummy(0), *cur = &dummy;
        while ( l1 && l2 ) {
            if ( l1->val < l2->val ) {
                cur->next = l1;
                l1 = l1->next;
            }  else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if  ( l1 )
            cur->next = l1;
        if  ( l2 ) 
            cur->next = l2;
        return dummy.next;
    }
};


// This solution employs the priority-queue data structure to compare the k emlements from the lists
// Then it pops out the elements one by one and push the next of the poped elements. 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *& a, ListNode *& b) {
            // the priority maintains the top elments as the "largest" according the given comparison method 
            // Therefore, we define the opposite compare method to maintain the smallest is at the top
            return a->val > b ->val;       
        };
        
        priority_queue<ListNode*, vector<ListNode*>,decltype(cmp) > pq(cmp);
        for ( auto list_x : lists ) {
            if ( list_x ) 
                pq.push(list_x);
        }
        
        ListNode dummy(-1),  *cur = &dummy;
        while( !pq.empty() ){
            auto t = pq.top();
            pq.pop();
            cur->next = t; 
            cur = cur->next;
            if ( t->next) 
                pq.push(t->next);
        }
        
        return dummy.next;
    }
};

// We can put all data in an array and sort, and then put them back in a linked list
// O(n), O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> data; 
        for ( int i = 0; i < lists.size(); i++ )
        {   
            ListNode *cur = lists[i];
            while ( cur )
            {
                data.push_back( cur->val );
                cur = cur->next;
            }
        }
        
        sort( data.begin(), data.end() );
        ListNode dummy(-1), *tail = &dummy;
        for ( auto d : data )
        {
            ListNode *tmp = new ListNode(d);
            tail->next = tmp;
            tail = tail->next;
        }
        
        return dummy.next;
    }
};

// Could use count-sorting like algorithm 
// The potential drawback is that it requires dynamic memory allocation
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1), *tail = &dummy;
        int mx = INT_MIN, mn = INT_MAX;
        unordered_map<int,int> m;
        for ( auto node : lists )
        {
            ListNode *t = node;
            while ( t )
            {
                mx = max(mx,t->val);
                mn = min(mn,t->val);
                m[t->val]++;
                t = t->next;
            }
        }
        
        for ( int num = mn; num <= mx; num++ )
        {
            if ( !m[num] )
                continue;
            for ( int i = 0; i < m[num]; i++ )
            {
                ListNode *tmp = new ListNode(num);
                tail->next = tmp;
                tail = tail->next;
            }
        }
        
        return dummy.next;
    }
};