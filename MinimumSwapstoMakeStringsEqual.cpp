// Problem Description
/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.



Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2: 

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1
Example 4:

Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4


Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.

*/

// The idea is to find the positions which are different and we can perform swaps for each different pair we have 
// found. Then we have three cases: 
// xx vs yy: for this pair we just need one swap to make them equal, i.e., xy vs yx or yx vs yx 
// yy vs xx: similarly, we just need one swap to make them equal, i.e., yx vs yx or xy vs xy 
// xy vs yx or yx vs xy: for this pair we need two swaps, first vertical swap, then it becomes either of the above two cases 

// Therefore, we can calcuate the number of different positions and categorize them as either x_difference or y_difference. 
// Then if both are even, then for each pair we need one swap, i.e., x_count/2 + y_count/2
// if both are odd, then we can a even number of pairs and one final type 3, which takes two swaps 
// If either of them is odd, then we cann't make them equal.

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x_count = 0, y_count = 0;
        for ( int i = 0; i < s1.size(); i++ )
        {
            if ( s1[i] == 'x' && s2[i] == 'y' )
                x_count++;
            else if ( s1[i] == 'y' && s2[i] == 'x' )
                y_count++;
        }
        
        int ans = x_count/2 + y_count/2;
        if ( x_count % 2 == 0 && y_count % 2 == 0 )
        {
            return ans;
        }
        else if ( (x_count + y_count) % 2 == 0 )
        {
            return ans + 2;
        }
        else 
            return -1;
    }
};
