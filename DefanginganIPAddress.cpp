// Problem Description 
/*
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
    A defanged IP address replaces every period "." with "[.]".
    Example 1:

    Input: address = "1.1.1.1"
    Output: "1[.]1[.]1[.]1"
    Example 2:

    Input: address = "255.100.50.0"
    Output: "255[.]100[.]50[.]0"
    

    Constraints:

    The given address is a valid IPv4 address.
 * 
 */

// Uses the find_first_of method to check and replace each '.'
// O(n), O(1)
class Solution {
public:
    string defangIPaddr(string address) {
        int dotpos = address.find_first_of('.');
        while( dotpos != string::npos ) {
            address.replace(dotpos,1,"[.]");
            dotpos = address.find_first_of('.',dotpos+3);
        }
        
        return address;
    }
};

// Uses a temp string to store the result
// O(n),O(n)
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for ( int i = 0; i < address.size(); i++ ) {
            if ( address[i] == '.' ) {
                res += "[.]";
            }
            else
            {
                res += address[i];
            }
        }
        return res;
    }
};