// Problem Description
/*
 * 
    Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

    You can use each character in text at most once. Return the maximum number of instances that can be formed.
 * 
 */

// Use hash map 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        const string pattern = "balloon";
        int charfrequence[26] = {0};
        int NumofBallons = 0;
        for ( auto ch : text ) 
            charfrequence[ch-'a']++;
        while ( 1 ) {
            for ( auto ch : pattern ) {
                if ( charfrequence[ch-'a'] == 0 ) 
                    return NumofBallons;
                charfrequence[ch-'a']--;
            }
            NumofBallons++;
        }
    }
};