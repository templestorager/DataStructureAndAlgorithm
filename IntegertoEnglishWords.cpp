// Problem Description 
/*
    Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

    Example 1:

    Input: 123
    Output: "One Hundred Twenty Three"
    Example 2:

    Input: 12345
    Output: "Twelve Thousand Three Hundred Forty Five"
    Example 3:

    Input: 1234567
    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    Example 4:

    Input: 1234567891
    Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
    Accepted
    124,838
    Submissions
    496,008
    Seen this question in a real interview before?
 * 
 */

// The solution is straightforward. It doesn't test any specific algorithm or data structrue
// The whole idea is just to process the number in chunks of three digits. 

class Solution {
public:
    string numberToWords(int num) {
        string res = convertUnit( num % 1000 );
        vector<string> highunits = { "Thousand", "Million", "Billion"};
        int i = 0; 
        while ( num /= 1000 ) {
            res = num % 1000 ? convertUnit(num % 1000) + " " + highunits[i] + " " + res: res; 
            i++;
        }
        
        while ( res.back() == ' ' ) 
            res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    
    // Handle a group of at most three digits
    string convertUnit( int num ) {
        vector<string> lessthan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> morethan20lessthanhundred = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res; 
        int hundreds = num / 100, tens = num % 100, ones = num % 10; 
        res = tens < 20 ? lessthan20[tens] : morethan20lessthanhundred[tens/10] + ( ones ? " " + lessthan20[ones] : "");
        if ( hundreds > 0 ) {
            res = lessthan20[hundreds] + " Hundred" + ( tens ? " " + res : "");
            return res;
        }
        
        return res;
    }
};