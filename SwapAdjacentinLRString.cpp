// Problem Description
/*
 In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
*/

// The key point is to understand and tranlate the problem
// We are only allowed for transitions of "XL"--->"LX" and "RX"--->"XR", which indicates L and R can only 
// move to left and right, respectively, and L and R's can never cross.  Therefore, if the target string is reachable by performing these moves, 
// the characters on the same positions should be the same if X is not considered and the L position in start string should be no less than 
// that of the target string and the R position of the start string should be no larger than that of the target string. 
class Solution {
public:
    bool canTransform(string start, string end) {
        if ( start.length() != end.length() ) 
            return false;
        int s = 0, e = 0, n = start.length();
        while ( s < n && e < n )
        {
            while ( s < n && start[s] == 'X' ) 
                s++;
            while ( e < n && end[e] == 'X' )
                e++;
            if ( start[s] != end[e] )
                return false;
            if ( start[s] == 'L' && s < e )
                return false;
            if ( start[s] == 'R' && s > e )
                return false;
            s++;
            e++;
        }
        return true;
    }
};

// This idea counts the amounts of 'L' and 'R'
// We need to observe the order of increment and then decrement. Given the order coud be different for 'L' and 'R', 
// we have to check end for 'L' and start for 'R'. 
class Solution {
public:
    bool canTransform(string start, string end) {
        if ( start.length() != end.length() ) 
            return false;
        int cntL = 0, cntR = 0, i = 0, n = start.length();
        while ( i < n )
        {
            if ( end[i] == 'L' ) cntL++;
            if ( start[i] == 'R' ) cntR++;
            if ( end[i] == 'R' ) cntR--;
            if ( start[i] == 'L' ) cntL--;
            if ( cntL < 0 || cntR < 0 || cntL * cntR > 0 )
                return false;
            i++;
        }
        return ( cntL == 0 && cntR == 0 );
    }
};