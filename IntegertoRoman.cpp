// Problem Description 
/*
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

    Example 1:

    Input: 3
    Output: "III"
    Example 2:

    Input: 4
    Output: "IV"
    Example 3:

    Input: 9
    Output: "IX"
    Example 4:

    Input: 58
    Output: "LVIII"
    Explanation: L = 50, V = 5, III = 3.
    Example 5:

    Input: 1994
    Output: "MCMXCIV"
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

// This function constructs the base system and iteratively checks the base until all magnitude 
// has been consumed 
// O(n), O(1)
class Solution {
public:
    string intToRoman(int num) {
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> str{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for ( int i = 0; i < val.size(); i++ ) {
            while ( num >= val[i] ) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

// This solution leverage the given constraint that the val is in the range [1-3999]
// so it construct the thousands, hundreds, tens and units and index it directly
class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<string> M_dominate{"","M","MM","MMM"};   // 1000-3000
        vector<string> C_dominate{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};  // 100-900
        vector<string> X_dominate{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};   // 10-90
        vector<string> I_dominate{"","I","II","III","IV","V","VI","VII","VIII","IX"};   // 0-9
        res += M_dominate[num / 1000];
        res += C_dominate[(num%1000)/100];
        res += X_dominate[(num%100) / 10];
        res += I_dominate[num%10];
        return res;
    }
};