// Problem Description
/*
You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.
*/


// Given we are limited by the number of calls, we cann't use linear algorithm .
// 1. We first use binary search to find the mountain peak. 
//    Once we find the peak element, then the left half is ascending order and the right half is descreasing order 
// 2. Use binary search in the left side to find the target 
// 3. If not found in the left, continue to search on the right side 

/**
 * This is the MountainArray's API interface.
 * You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak, l = 0, h = mountainArr.length() - 1, res = -1;
        while( l < h )
        {
            int mid = (l+h)/2;
            if ( mountainArr.get(mid) > mountainArr.get(mid+1) )
            {
                h = mid;
            }
            else 
            {
                l = mid+1;
            }
        }
        
        peak = l;
        
        l = 0; 
        h = peak;
        while( l < h )
        {
            int mid = (l+h)/2;
            if ( mountainArr.get(mid) == target )
            {
                res = mid;
                break;
            }
            if ( mountainArr.get(mid) < target )
            {
                l = mid+1;
            }
            else 
            {
                h = mid;
            }
        }
        
        if ( res == -1 )
        {
            l = peak;
            h = mountainArr.length();
            while( l < h)
            {
                int mid = (l+h)/2;
                if ( mountainArr.get(mid) == target )
                {
                    res = mid;
                    break;
                }
                if ( mountainArr.get(mid) < target )
                {
                    h = mid;
                }
                else 
                {
                    l = mid+1;
                }
            }
        }
        
        return res;
        
    }
};