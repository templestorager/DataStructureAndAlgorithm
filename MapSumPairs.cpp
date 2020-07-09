// Problem Description
/*
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 */

// Straightford solution: check each existing pair to see if it contains the prefix 
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        m.clear();
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        unordered_map<string,int>::iterator it;
        int sum = 0;
        for ( it = m.begin(); it != m.end(); it++ )
        {
            if ( it->first.substr(0,prefix.size()) == prefix )
                sum += it->second;
        }
        return sum;
    }
private: 
    unordered_map<string, int> m;
};

