// Problem Description
/*
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
*/

// The key idea is to identify how many possibilities of any element being the minimum of a subarray. 
// Therefore, we iterate the array and check the possibilities of each element. 
// For the first element, we know there is only one subarray and the element is the minimum. 
// For any element A[i], we compare it with it's previous elements. Then there are two cases:
// 1. A[i] is larger or equal than its immediately previous element A[i-1]. In this case, expanding the subarrays 
//    containing A[i-1] to include A[i] doesn't change the number of the subarrays and their respective mininums (still being A[i-1])
//    i.e., it will still have the same sum as A[i-1]. Note that the element itself alone can be a valid subarray. 
//    Therefore, the value of A[i] is the value of A[i-1] + A[i]; 
// 2. A[i] is smaller than A[i-1], then we need to move backward to find an element which is smaller or equal to A[i]. 
//    Say A[j] is the element. 
//    If j < 0, i.e., A[i] is the smallest elment, then we have (i+1) subarrays ending with A[i]. 
//    If j >= 0, then there two type of subarrays. One is the subarray having A[j] as the minimum, whose sum won't change 
//    the other type having A[i] as the minimum whose number is (i-j) (i.e., A[j+1...i]).
// From the above analysis, we know that the current sum is based on the previous sums, so we use dynamic programming 
// O(n^2) O(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size(), sum = 0;
        int M = 1e9 + 7;
        if ( n == 0 )
            return sum;
        vector<int> rightmostdpsum(n);
        sum += A[0];
        rightmostdpsum[0] = A[0];
        for ( int i = 1; i < n; i++ )
        {
            if ( A[i] >= A[i-1] )
                rightmostdpsum[i] = rightmostdpsum[i-1] + A[i];
            else {
                int j = i - 1;
                while ( j >= 0 && A[j] > A[i] )
                    j--;
                rightmostdpsum[i] = j < 0 ? (i+1) * A[i] : (rightmostdpsum[j]+(i-j)*A[i]);
            }
            
            sum = ( sum + rightmostdpsum[i] ) % M;
        }
        
        return sum;
    }
};

// The idea of this method is essentially the same as the above one with an optimization, which significantly reduces the complexity 
// In the above approach, when wen need to find the first element that is less than the current element, we do a linear backward searching. 
// We can facilitate the search for the first less element on the left side by running a decreasing monotone stack. 
// Having this stack, the first element less than the current element is readily avaiable as the top element of the stack
// Dp[i] means the sum of subarrays ending at A[i]. 

// Monotone stack:
// Increasing stack maitains the left-side first element that is less than the current element 
// Descreasing stack maintains the left-side first element that is larger than the current element 
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size(), sum = 0, M = 1e9 + 7;
        if ( n == 0 )
            return sum;
        vector<int> rightmostdpsum(n+1);
        rightmostdpsum[0] = 0;
        stack<int> increasingstack{{-1}};
        for ( int i = 0; i < A.size(); i++ )
        {
            while( increasingstack.top() != -1 && A[i] <= A[increasingstack.top()] )
                increasingstack.pop();
            rightmostdpsum[i+1] = rightmostdpsum[increasingstack.top()+1] + (i-increasingstack.top()) * A[i];
            increasingstack.push(i);
            sum = ( sum + rightmostdpsum[i+1] ) % M;
        }
        
        return sum;
    }
};

// If there is no previous elements less than the current element, i.e., the idx of the previous less element of the current element 
// is -1, it means the current element is the smallest so far, and there are (i+1) subarrays with the current element being the right-most 
// Similarly, if there is no next elements less than the current element, i.e., the idx of the next less element of the current element is n, 
// it means the current element is the smallest among the remaining elements, therefore add any of the remaining elements to the subarrays with 
// the current element being the minimum does NOT change it's being minimum. 

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int sum = 0, M = 1e9 + 7;
        int n = A.size(), dp[n]; 
        stack<int> ims;
        for ( int i = 0; i < n; i++ )
        {
            while ( !ims.empty() && A[ims.top()] >= A[i] )
                ims.pop();
            int prevlessidx = ims.empty() ? -1 : ims.top();
            dp[i] = prevlessidx == -1 ? (i+1) * A[i] : dp[prevlessidx] + (i-prevlessidx) * A[i];
            ims.push(i);
            sum += dp[i] % M;
            sum %= M;
        }
        return sum;
    }
};

// Take [3,6,4,8,10,3,9] for example, 
// The PreLess and NextLess of idx 2( A[2] == 4 ) of 0 (A[0] == 3) and 5 (A[5] == 3), respectively. 
// Therefore, the number of subarray with A[2] being the right-most and minimu is (i-PreLess) = (2-0) = 2, i.e., 
// [4], [6,4]. 
// And we expand those subarrays to include elements until NextLess-1, i.e., A[4], with A[2] still being the minimum,
// the number of which is NextLess - 1 - 2 = 5 - 3 = 2.
// [4,8],[6,4,8],[4,8,10],[6,4,8,10], 
// So totally, we have (i-left[i]) * (right[i]-i) times A[i] for each A[i].
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int sum = 0, M = 1e9+7;
        int n = A.size();
        vector<int> left, right;
        if ( n == 0 )
            return sum;
        ComputePrevLessIdxArray(left,A);
        ComputeNextLessIdxArray(right,A);
        for ( int i = 0; i < n; i++ )
        {
            sum += (i-left[i]) * (right[i]-i) % M *A[i] % M;
            sum %= M;
        }
        
        return sum;
    }
    
    void ComputePrevLessIdxArray( vector<int> &PreviousLessIdx, const vector<int> &A )
    {
        // IMS: increasing monotone stack 
        stack<int> ims;
        PreviousLessIdx.clear();
        for ( int i = 0; i < A.size(); i++ )
        {
            while ( !ims.empty() && A[ims.top()] > A[i] )
                ims.pop();
            PreviousLessIdx.push_back( ims.empty() ? -1 : ims.top() );
            ims.push(i);
        }
    }
    
    void ComputeNextLessIdxArray( vector<int> &NextLessIdx, const vector<int> &A )
    {
        stack<int> ims; 
        NextLessIdx.clear();
        NextLessIdx = vector<int>(A.size());
        for ( int i = A.size() - 1; i >= 0; i-- )
        {
            while( !ims.empty() && A[ims.top()] >= A[i] )
            {
                ims.pop();
            }
            NextLessIdx[i] = ims.empty() ? A.size() : ims.top();
            ims.push(i);
        }
    }
};