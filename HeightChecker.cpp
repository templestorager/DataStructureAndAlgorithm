// Problem Description
/*
    Students are asked to stand in non-decreasing order of heights for an annual photo.
    Return the minimum number of students not standing in the right positions.  
    (This is the number of students that must move in order for all students to be standing 
    in non-decreasing order of height.)

    Example 1:

    Input: [1,1,4,2,1,3]
    Output: 3
    Explanation: 
    Students with heights 4, 3 and the last 1 are not standing in the right positions.
    
    Note:

    1 <= heights.length <= 100
    1 <= heights[i] <= 100
 * 
 */

// Basic idea is to sort the array first and then check whether it is in the place where it should be 

// this method uses the O(nlgn) sorting algorithm, constant space 
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ooo = 0;
        vector<int> temp(heights);
        sort( temp.begin(), temp.end() );
        for ( int i = 0; i < temp.size(); i++ ) {
            if ( temp[i] != heights[i] ) 
                ooo++;
        }
        
        return ooo;
    }
};

// similar idea, but uses count sorting considering the given constrains, which has O(n) complexity

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ooo = 0;
        vector<int> temp;  
        vector<int> count(101,0);
        
        for ( int i = 0; i < heights.size(); i++ ) {
            count[heights[i]]++;
        }
        
        for ( int i = 1; i < 101; i++ ) {
            while( count[i]-- ) 
                temp.push_back(i);
        }
        
        for ( int i = 0; i < temp.size(); i++ ) {
            if ( temp[i] != heights[i] ) 
                ooo++;
        }
        
        return ooo;
    }
};