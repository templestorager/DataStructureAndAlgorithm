// This solution first resverses the entire string
// Then it reverses each word in the string again
// all operations are done in-place. 
// Time complexity O(n), space complexity O(1)
class Solution {
public:
    string reverseWords(string s) {
        int idx = 0, n = s.size();
        reverse( s.begin(), s.end() );
        for ( int i = 0; i < n; i++ ) {
            if ( s[i] != ' ' ) {
                if ( idx != 0 )
                    s[idx++] = ' ';
                int j = i;
                while ( j < n && s[j] != ' ' )
                    s[idx++] = s[j++];
                reverse( s.begin()+idx-(j-i), s.begin() + idx );
                i = j;
            }
        }
        s.resize(idx);
        return s;
    }
};

// this solution uses the input stream method
// time complexity O(n) space complexity O(n)
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp,res;
        is >> res;   // extrace the first word 
        while ( is >> tmp )
            res = tmp + " " + res;
        if ( !res.empty() && res[0] == ' ' )  // if it is a space-only string 
            res = "";
        return res;
    }

};

// this solution uses both the input stream and getline function 
// the getline function only recognizes and consumes (extracts and discards) one delimiter  
// so if there are multiple spaces, then empty words will be returned and should NOT be concatenated to 
// the string to return

class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string res = "";
        string word = "";
        while ( getline(is, word, ' ') ){
            if ( word.empty() )
                continue;
            res = res.empty() ? word: word + " " + res;
        }
        return res;
    }

};

// This solution does one pass 

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int strlen = s.length();
        for( int i = strlen - 1; i >= 0; i-- ) {
            if ( s[i] == ' ' )
                strlen = i;
            else if ( i == 0 || s[i-1] == ' ' ) {
                if ( !res.empty() )
                    res.append(" ");
                res.append( s.substr(i,strlen -i) );
            }
        }
        return res;
    }

};
