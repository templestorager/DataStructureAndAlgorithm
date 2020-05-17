// Problem Description 
/* 
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

// Brute force solution 
// This equated nume should be in the range [min,max]. We check each possible case and find the smallest number of 
// moves.
// O(n*diff), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if ( nums.size() == 0 ) 
            return 0;
        int len = nums.size(); 
        int res = INT_MAX;
        int low = nums[0], high = nums[0];
        for ( int i = 1; i < len; i++ )
        {
            if ( nums[i] < low )
                low = nums[i];
            if ( nums[i] > high )
                high = nums[i];
        }
        
        for ( int equal_val = low; equal_val <= high; equal_val++ )
        {
            long sum = 0;
            for ( auto num : nums )
                sum += abs(num-equal_val);
            if ( sum < res )
                res = sum;
        }
        return res;   
    }
};

// Actually we can just consider the existing elements in the array rather then the whole range as the final equal value. 
// There is some trivial proof to show that this will result in fewer moves than choosing a value not existing in the array.
// O(n^2), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        if ( n == 0 )
            return 0;
        for ( auto val : nums )
        {
            long sum = 0;
            for ( auto num : nums )
                sum += abs( num - val );
            if ( sum < res )
                res = sum;
        }
        
        return res;
    }
};

// The following method is similar to the above solution, but use sorting to facilitate the calculation 
// Specifically, for an element nums[i] to be considered as the final value, the amount of increment moves before it is equal to 
// nums[i]*i - sum(0...i-1), and the amount of decrement moves after it (including itself which is 0) is remaining sum (total_sum - sum) 
// minus nums[i] * ( len - i ). 
// O(nlogn), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        long res = INT_MAX, sum = 0, total_sum = 0;
        int len = nums.size();
        for ( auto num : nums )
            total_sum += num;
        for ( int i = 0; i < nums.size(); i++ )
        {
            long moves = ((long)nums[i]*i - sum) + (total_sum-sum) - (long)nums[i]*(len-i);
            if ( moves < res )
                res = moves;
            sum += nums[i];
        }
        
        return res;
    }
};

// There is some math proof demonstrating that the median of the sorted array is the final value which minimizes 
// the moves, because the median is the only value which satisfies the derivative of the funtion respresenting the sums of before 
// elements and after elements being equal. 
// O(nlogn), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long res; 
        sort( nums.begin(), nums.end() );
        for ( int i = 0; i < nums.size(); i++ )
        {
            res += abs(nums[i]-nums[nums.size()/2]);
        }
        
        return res;
    }
};

// This following method is kind of tricky and does not require to know the median at all. 
// In a sorted array, assume the final value is val, then the moves of max is (max-val) and 
// the moves of min is (val-min). So the total moves of max and min is (max-val)+(val-min) 
// = max - min, regardless of the value. Therefore, we can progress to shrink the range 
// O(nlogn), O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int res = 0;
        sort( nums.begin(), nums.end() );
        while ( l < r )
        {
            res += nums[r] - nums[l];
            l++;
            r--;
        }
        
        return res;
    }
};

// The following method uses the quick-sort idea to find the median whose rank is size()/2
// bringing down the complexity from O(nlogn) to O(n) on average. 
// But the quick-find could increase to O(n^2) in the worst case 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        int median = select_rank_num( nums, 0, nums.size()-1,nums.size()/2);
        for ( auto num : nums )
            sum += abs(median - num);
        return sum;
    }
    
    int select_rank_num( vector<int> &data, int l, int r, int k)
    {
        if ( l == r )
            return data[l];
        int pivotidx = partition(data,l,r);
        if ( pivotidx == k )
        {
            return data[k];
        }
        else if ( k < pivotidx )
        {
            return select_rank_num(data,l,pivotidx-1,k);
        } else {
            return select_rank_num(data,pivotidx+1,r,k);
        }
    }
    
    int partition( vector<int> &data, int l, int r )
    {
        int pivot = data[r];
        int i = l - 1;
        for ( int j = l; j < r; j++ )
        {
            if ( data[j] <= pivot )
            {
                swap(data[j],data[i+1]);
                i++;
            }
        }
        swap(data[i+1],data[r]);
        return i+1;
    }
};