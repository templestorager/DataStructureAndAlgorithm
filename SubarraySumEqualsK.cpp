// Problem Descirption 
/*
 * Given an array of integers and an integer k, you need to find the total number of 
 * continuous subarrays whose sum equals to k.
 */

// Straightforward solution: check the sum of each continuous subarray starting from a given index 
// pitfall: don't enable the break statement, as it will cause errors if the following num is zero,
// which doesn't increase the current sum.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numsubarrays = 0;
        for( int i = 0; i < nums.size(); i++ ) {
            int sum = 0;
            for ( int j = i; j < nums.size(); j++ ) {
                sum += nums[j];
                if ( sum == k ) {
                    numsubarrays++;
                    //break;
                }
            }
        }
        return numsubarrays;
    }
};

// This solution has a little optimization, using accumulative sums. 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numsubarrays = 0;
        // use an accumulative sum array: sum[i] = num[0]+...+nums[i-1];
        int AccumSum[nums.size() + 1];
        AccumSum[0] = 0;
        for ( int i = 1; i <= nums.size(); i++ ) {
            AccumSum[i]=AccumSum[i-1] + nums[i-1];
        }
        
        for ( int i = 0; i < nums.size(); i++ ) {
            for( int j = i+1; j <= nums.size(); j++ ) {
                if ( AccumSum[j] - AccumSum[i] == k ) 
                    numsubarrays++;
            }
        }
        
        return numsubarrays;
    }
};

// This solution keeps track of the accumulative sums, by using a map structure 
// A map entry associates the accumulative sum with the number of occurences of the sum
// The key point is to understand that the meaning of map[CurrentSum - k]:
// Each sum corresponds to an index (idx_s) and if the sum is at k difference from the sum of the index 
// being examinzed (idx_e), the following subarray (str[idx+1]...array[idx_e]) sums up to k, which is then 
// a valid subarray. 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numsubarrays = 0, accumSum = 0;
        unordered_map<int,int> m{{0,1}};
        for ( int i = 0; i < nums.size(); i++ ) {
            accumSum += nums[i];
            numsubarrays += m[accumSum-k];
            ++m[accumSum];
        }
        return numsubarrays;
    }
};
