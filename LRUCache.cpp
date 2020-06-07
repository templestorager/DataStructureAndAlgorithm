/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ); // Capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/
// basically we use a hashmap and a list. 
// the hashmap maps a key to its position (iterator) in the list 
// the list contains pairs of key and value.. we always push to the front and delete from the back 
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if ( it == m.end() )
            return -1;
        data.splice(data.begin(),data,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if ( it != m.end() )
            data.erase(it->second);
        data.push_front(make_pair(key,value));
        m[key] = data.begin();
        if ( m.size() > cap )
        {
            int key = data.rbegin()->first;
            data.pop_back();
            m.erase(key);
        }
    }
private:
    int cap;
    list<pair<int,int>> data;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};