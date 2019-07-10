// Problem Description 
/*
 * You're given strings J representing the types of stones that are jewels, and S representing 
 * the stones you have.  Each character in S is a type of stone you have.  You want to know how 
 * many of the stones you have are also jewels.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters 
 * are case sensitive, so "a" is considered a different type of stone from "A".
 * 
 * Example 1:
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * Example 2:
 * Input: J = "z", S = "ZZ"
 * Output: 0
 *  
 */

// This is a brute force approach, i.e., for each type of stone check whether it is also a jewel 
// O(m*n) O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewels = 0; 
        for( auto s : S ) {
            for ( auto j : J ) 
                if ( s == j ) {
                    jewels++;
                    break;
                }
        }     
        return jewels;
    }
};

// This solution uses set to store the Jewel and then check the stones
// O(m+n), O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewels = 0; 
        unordered_set<char> Jewelset;
        for ( auto j : J ) 
            Jewelset.insert(j);
        
        for ( auto s : S ) {
            if ( Jewelset.find(s) != Jewelset.end() )
                jewels++;
        }
        
        return jewels;
    }
};