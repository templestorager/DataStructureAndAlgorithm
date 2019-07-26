// Problem Description 
/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
    Example:

    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
 * 
 */

// O(m+n), O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m+n,0);
        int midx = 0, nidx = 0, residx = 0;
        while(midx < m && nidx < n) {
            if ( nums1[midx] >= nums2[nidx] ) {
                res[residx++] = nums2[nidx++];
            }
            else {
                res[residx++] = nums1[midx++];
            }
        }
        
        if ( midx == m && nidx == n) {
            nums1 = res;
            return;
        }
        if ( midx == m ) {
            for ( int i = nidx; i < n; i++ ) 
                res[residx++] = nums2[i];
        }
        else {
            for ( int i = midx; i < m; i++ ) {
                res[residx++] = nums1[i];
            }
        }
        nums1 = res;
        return;
    }
};

// Copy from the end 
// O(m+n), O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int residx = m + n - 1, midx = m - 1, nidx = n - 1; 
        while ( nidx >= 0 && midx >= 0 ) {
            nums1[residx--] = nums1[midx] >= nums2[nidx] ? nums1[midx--] : nums2[nidx--];
        }

        while ( nidx >= 0 ) 
            nums1[residx--] = nums2[nidx--];
        
        return;
    }
};