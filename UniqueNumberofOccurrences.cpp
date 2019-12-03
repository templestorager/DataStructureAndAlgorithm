// Problem Description
/*
    Given an array of integers arr, write a function that returns true if and only if the number 
    of occurrences of each value in the array is unique.

    Example 1:

    Input: arr = [1,2,2,1,1,3]
    Output: true
    Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
    Example 2:

    Input: arr = [1,2]
    Output: false
    Example 3:

    Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    Output: true
    

    Constraints:

    1 <= arr.length <= 1000
    -1000 <= arr[i] <= 1000
 */

// First establish a hashmap to record the occurrences of the each number and 
// then check the uniqueness of the occurrences using a set data structure 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> numoccurrence;
        unordered_set<int>  occurrenceset;
        for ( int i = 0; i < arr.size(); i++ ) {
            numoccurrence[arr[i]]++;
        }
        
        for ( unordered_map<int,int>::iterator it = numoccurrence.begin(); it != numoccurrence.end(); it++ ) {
            if ( occurrenceset.count(it->second) != 0 )
                return false;
            occurrenceset.insert(it->second);
        }
        
        return true;
    }
};