// Problem Description 
/*
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * 
 * Example 1:
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * Example 2:
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 */

// This solution is brute force. 
// For each step, we move the last element to the head and move all the other elements in a 
// cascading manner
// O(n*k), O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,previous;
        for ( int i = 0; i < k; i++ ) {
            previous = nums[nums.size()-1];
            for ( int j = 0; j < nums.size(); j++ )  {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};

// Notice that the i-th elment would be the (i+k)%len after k right rotate 
// So we use an temp array to store the final result and copy it back to the original array 
// O(n), O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> temp(len,0);
        for ( int i = 0; i < len; i++ ) {
            temp[(i+k)%len] = nums[i];
        }
        
        nums = temp;
    }
};

// This solution improves over the above approach by using avoiding using extra space 
// The key point to understanding this algorithm is to replace the elments in a cascading 
// manner, like cuckoo hash, i.e., num[idx] is position at num[(idx+k)%n], as so on... 
// It's also important to notice that the replacement traces form cycles and there are n/k 
// cycles. If we start from the i-th cycle (starting from num[i], i != 0 ), then it will first 
// meet at i. In this case, we just increment the cycle to move on to check the next cycle. 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int number_to_shift = nums[0], temp, cycle = 0, len = nums.size(),next_idx = 0;
        if ( len == 0 || k % len == 0 ) 
            return ;
        for ( int i = 0; i < len; i++ ) {
            int next_idx = (next_idx+k)%len;
            temp = nums[next_idx];
            nums[next_idx] = number_to_shift;
            number_to_shift = temp;
            if ( next_idx == cycle ) {
                next_idx = ++cycle;
                number_to_shift = nums[next_idx];
            }
        }
    }
};

// This solution makes three reverses for the three parts respectively. 
// Note the special case where k could be large than the array size. 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

// This solution moves the front elements to the end using push_back and erase. 
// O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        for ( int i = 0; i < len-k; i++ ) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        } 
    }
};

// This solution uses the stl::rotate function. 
// Note the stl::rotate function paramaters are: 
// stl::rotate(begin_iterator, new_begin, end_iterator)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if ( nums.size() == 0 ) 
            return ;
        k %= nums.size();
        std::rotate(nums.begin(),nums.begin()+nums.size()-k,nums.end());
    }
};

// This solution is elegant. 
// Key point to appreciating it is perceiving it as recursive process. 
// Basically, for each loop we set k elments to their correct position. 
// Then we advance to the check starting from nums[k] ( since nums[0...k-1] are already in palce)
// with a reduced length of (n-k). 
// For this new shortened subproblem, we repeat the same procedure 
// One key thing is than we need to update the check length of k, as we reduce the subproblem length 
// k may become larger than the length. 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(); 
        if ( len == 0 || k == 0 ) 
            return ;
        
        for ( int start = 0; k %= len; len -= k, start += k ) {
            for ( int i = 0; i < k; i++ ) {
                swap(nums[start+i],nums[start + len-k+i]);
            }
        }
    }
};