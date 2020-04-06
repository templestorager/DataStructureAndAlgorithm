// Problem Description 
/*
 Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length(), nb = b.length();
        string res; 
        int reslen;
        int carry = 0;
        if ( na > nb )
        {
            for ( int i = 0; i < na - nb; i++ )
                b.insert(b.begin(),'0');
            reslen = na;
        }
        else 
        {
            for ( int i = 0; i < nb - na; i++ )
                a.insert(a.begin(),'0');
            reslen = nb;
        }
        
        for ( int i = reslen - 1; i >= 0; i-- )
        {
            int val = (a[i]-'0') ^ (b[i]-'0') ^ carry;
            carry = !(a[i] - '0') + !(b[i] - '0') + !carry <= 1;    // will have a carry if there is at most one zero among the three 
            if ( val == 0 )
                res.insert(res.begin(),'0');
            else
                res.insert(res.begin(),'1');
        }
        if ( carry )
            res.insert(res.begin(),'1');
        return res;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length() - 1, nb = b.length() - 1;
        string res;
        int carry = 0;
        while ( na >= 0 || nb >= 0 )
        {
            int val_a = na >= 0 ? a[na--]-'0' : 0;
            int val_b = nb >= 0 ? b[nb--]-'0' : 0;
            int sum = val_a + val_b + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        if ( carry )
            res = "1" + res;
        return res;
    }
};