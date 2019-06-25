// This solution first resverses the entire string
// Then it reverses each word in the string again
// all operations are done in-place. 


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