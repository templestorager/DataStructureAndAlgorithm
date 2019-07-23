// Problem Description 
/* 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is 
 * missing from the array.
    Example 1:

    Input: [3,0,1]
    Output: 2
    Example 2:

    Input: [9,6,4,2,3,5,7,0,1]
    Output: 8
    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only 
    constant extra space complexity?
 * 
 */

// This solution sorts the array and checks the expected number 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        if ( nums[nums.size()-1] != nums.size() ) 
            return nums.size();
        else if ( nums[0] != 0 ) 
            return 0;
        for ( int i = 1; i < nums.size(); i++ ) {
            int expectNum = nums[i-1] + 1;
            if ( expectNum != nums[i] ) 
                return expectNum;
        }
        return -1;
    }
};

// This solution sets up a set and checks each
// O(n), O(n) 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s;
        for ( int num : nums ) 
            s.insert(num);
        
        for ( int number = 0; number < nums.size() + 1; number++ ) {
            if ( !s.count(number) )
                return number;
        }
        
        return -1;
    }
};

// This solution XORs the given nums with [0..n]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(); 
        for ( int i = 0; i < nums.size(); i++ ) {
            res ^= i ^ nums[i];
        }
        
        return res;
    }
};

// This solution directly applies the Gauss formula.
// O(n), O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalsum = nums.size() * (nums.size() + 1) / 2;
        for ( int i = 0; i < nums.size(); i++ ) 
            totalsum -= nums[i];
        return totalsum;
    }
};

// sort and then binary search 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size();
        while ( l < r ) { 
            int mid = l + (r-l)/2;
            if ( nums[mid] > mid )
                r = mid;
            else 
                l = mid + 1;
        }
        return r;
    }
};

// This solution takes advantage of the statistics about 0s and 1s of the LSb, 
// i.e., if the number of 0s is larger than 1s, then a bit 1 is missing 
//       and if the number of 0 is less than or equal to 1, then a 0 is missing. 
// It performs the following steps: 
// 1. check the counts of 0s and 1s 
// 2. based on the counts of 0s and 1s, figure out the missing 0 or 1 for the current bit position
// 3. remove the numbers whose bits are opposite to the missing bit value and continue with 
//    the next bit position 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return findMissing(nums,0);
    }
    
    int findMissing(vector<int> &nums, int col) {
        if ( nums.empty() ) 
            return 0;
        vector<int> zeros, ones;
        for ( int i = 0; i < nums.size(); i++ ) { 
            if( nums[i] & 1 << col ) 
                ones.push_back(nums[i]);
            else 
                zeros.push_back(nums[i]);
        }
        
        if ( zeros.size() <= ones.size() ) {
            int v = findMissing(zeros,col+1);
            return v << 1 | 0;
        } else {
            int v = findMissing(ones,col+1);
            return v << 1 | 1;
        }
    }
};