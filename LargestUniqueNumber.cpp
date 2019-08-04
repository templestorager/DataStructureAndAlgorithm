// Problem Description 
/*
 * 
    Given an array of integers A, return the largest integer that only occurs once.
    If no integer occurs once, return -1.
    Example 1:

    Input: [5,7,3,9,4,9,8,3,1]
    Output: 8
    Explanation: 
    The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.
    Example 2:

    Input: [9,9,8,8]
    Output: -1
    Explanation: 
    There is no number that occurs only once.
    Note:

    1 <= A.length <= 2000
    0 <= A[i] <= 1000
 * 
 */

// This solution first sorts the array and searches for the number appearing only once from the end 
// important to check corner cases. 
// O(nlgn), O(1)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int res = -1;
        int n = A.size();
        if ( n == 1 ) 
            return A[0];
        sort( A.begin(), A.end() );
        for ( int i = n-1; i > 0; ) {
            if ( A[i] != A[i-1] ) {
                return A[i];
            } else {
                if ( i == 1 ) 
                    return -1;
                while( A[i] == A[i-1] ) 
                    i--;
                i--;
                if ( i == 0 ) 
                    return A[i];
            }
        }
        
        return -1;
    }
};

// This solution uses an extra map data structure to record the number of a number's frequency 
// Then check the largest values' frequency. 
// O(nlgn), O(n)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int res = -1;
        int n = A.size();
        unordered_map<int,int> valfrequency;
        if ( n == 1 ) 
            return A[0];
        
        for ( int i = 0; i < n; i++ ) 
            valfrequency[A[i]]++;
        sort( A.begin(), A.end() );
        for ( int i = n-1; i >= 0; i-- ) {
            if ( valfrequency[A[i]] == 1 )
                return A[i];
        }
        
        return -1;
    }
};

// This solution uses a set to filter out the unique numbers 
// The seen map is used to avoid number appear an odd and more than two appearence to be incorrectly classified 
// as a unique number 
// O(n), O(n)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_set<int> uniquenumbers;
        unordered_map<int,bool> seen;
        int largest = INT_MIN;
        for ( int i = 0; i < A.size(); i++ ) {
            if ( uniquenumbers.count(A[i]) ) {
                uniquenumbers.erase(A[i]);
            } 
            else if ( !seen[A[i]] ) {
                uniquenumbers.insert(A[i]);
                seen[A[i]] = true;
            }
        }
        if ( uniquenumbers.size() == 0 )
            return -1;
        for ( int num : uniquenumbers ) {
            if ( num > largest)
                largest = num;
        }
        return largest;
    }
};

// Similar idea as the above, but uses two sets 
// O(n), O(n)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_set<int> uniquenumbers;
        unordered_set<int> allnumbers;

        int largest = INT_MIN;
        for ( int i = 0; i < A.size(); i++ ) {
            if ( !allnumbers.count(A[i]) ) {
                uniquenumbers.insert(A[i]);
                allnumbers.insert(A[i]);
            } 
            else {
                uniquenumbers.erase(A[i]);
            }
        }
        if ( uniquenumbers.size() == 0 )
            return -1;
        for ( int num : uniquenumbers ) {
            if ( num > largest)
                largest = num;
        }
        return largest;
    }
};