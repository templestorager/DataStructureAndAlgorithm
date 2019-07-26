// Problem Description 
/*
 * Given an array A of non-negative integers, return an array consisting of all the even elements 
 * of A, followed by all the odd elements of A.

    You may return any answer array that satisfies this condition.
    Example 1:

    Input: [3,1,2,4]
    Output: [2,4,3,1]
    The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
    

    Note:

    1 <= A.length <= 5000
    0 <= A[i] <= 5000
 *
 */
// O(n),O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for ( auto num : A ) {
            if ( num % 2 )
                odd.push_back(num);
            else
                even.push_back(num);
        }
        
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
    }
};

// O(n),O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int evenidx = 0, oddidx = 0;
        for ( ; oddidx < A.size(); oddidx++ ) {
            if ( !A[oddidx] % 2 ) {
                swap(A[evenidx++],A[oddidx]);
            }
        }
        return A;
    }
};
// O(n), O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        partition(A.begin(),A.end(),[](auto a) { return !(a % 2); });
        return A;
    }
};