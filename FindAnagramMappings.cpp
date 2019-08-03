// Problem Description 
/*
 *  Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by 
 * randomizing the order of the elements in A.
 * We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A 
 * appears in B at index j.
    These lists A and B may contain duplicates. If there are multiple answers, output any of them.

    For example, given

    A = [12, 28, 46, 32, 50]
    B = [50, 12, 32, 46, 28]
    We should return
    [1, 4, 3, 2, 0]
    as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
    Note:

    A, B have equal lengths in range [1, 100].
    A[i], B[i] are integers in range [0, 10^5].
 * 
 */

// Brute force 
// O(mXn), O(1)
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        if ( A.size() != B.size() || A.size() == 0 )
            return res;
        int a = A.size(), b = B.size();
        for ( int i = 0; i < a; i++ ) {
            for ( int j = 0; j < b; j++ ) {
                if ( A[i] == B[j] ) {
                    res.push_back(j);
                    break;      // handle duplicates 
                }
            }
        }
        
        return res;
    }
};

// Uses a map to store the value of B to its index, then checks each value of A
// O(m), O(n), m and n are the size of A and B, respectively. 
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int,int> bmap;
        int a = A.size(), b = B.size();
        if ( a != b || a == 0 )
            return res;
        for ( int i = 0; i < b; i++ ) 
            bmap[B[i]] = i;
        for ( int i = 0; i < a; i++ ) 
            res.push_back(bmap[A[i]]);
        return res;
    }
};