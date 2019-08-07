// Problem Description
/*
 *
    Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

    Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

    If S[i] == "I", then A[i] < A[i+1]
    If S[i] == "D", then A[i] > A[i+1]
    

    Example 1:

    Input: "IDID"
    Output: [0,4,1,3,2]
    Example 2:

    Input: "III"
    Output: [0,1,2,3]
    Example 3:

    Input: "DDI"
    Output: [3,2,0,1]
    

    Note:

    1 <= S.length <= 10000
    S only contains characters "I" or "D".
 * 
 */

// This approach is brute force method. It uses the STL function next_permutation to generate 
// lexiographically order permutation and checks the permutation satifies the given "ID" requirement or 
// not. The end result is that this solution returns the lexicographicall smallest permutation satifying the 
// given condition. 
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        bool found = false;
        vector<int> permute;
        for ( int i = 0; i <= n; i++ ) {
            permute.push_back(i);
        }
        
        do {
            if ( MatchString(S,permute) ) {
                found = true;
                break;
            }
        } while(next_permutation(permute.begin(),permute.end()));
        
        if ( found ) {
            return permute;
        }
        else {
            return vector<int> ({});
        }
    }
    
    bool MatchString( string S, vector<int> permute) {
        for ( int i = 0; i < S.size(); i++ ) {
            if ( S[i] == 'I' ) {
                if ( permute[i] >= permute[i+1] ) 
                    return false;
            }
            
            else if ( S[i] == 'D' ) {
                if ( permute[i] <= permute[i+1] ) {
                    return false;
                }
            }
        }
        return true;      
    }
};

// This solution constructs the permutation according to the given requirement. 
// Specifically, if we encounter an "I", we put the currently smallest number. 
// if we encount a "D", then we put the currently largest number 
// O(n), O(1)
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int low = 0, high = S.size();
        for ( auto ch : S ) {
            if ( ch == 'I' ) {
                res.push_back(low);
                low++;
            }
            if ( ch == 'D' ) {
                res.push_back(high);
                high--;
            }
        }
        res.push_back(high); // low and high are the same
        return res;
    }
};