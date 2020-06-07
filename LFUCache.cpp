// Problem Description
/*
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

 

Follow up:
Could you do both operations in O(1) time complexity?
*/

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if ( m.count(key) == 0 )
            return -1;
        freq[m[key].second].erase(iter[key]);
        ++m[key].second;
        freq[m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();
        if ( freq[minFreq].size() == 0 )
            ++minFreq;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if ( cap <= 0 )
            return ;
        if ( get(key) != -1 )
        {
            m[key].first = value;
            return;
        }
        if ( m.size() >= cap )
        {
            m.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = {value,1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }
    
private:
    int cap, minFreq;
    unordered_map<int, list<int> > freq;   // map the freq to the keys having the same frequencies 
    unordered_map<int, list<int>::iterator> iter; // map the key to its position in the lists 
    unordered_map<int, pair<int,int> > m;   // map the key to the pair containing the value and its frequency  
};