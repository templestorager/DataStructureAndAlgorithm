// Problem Description
/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

// Two pass to calculate and then one pass to overwrite 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int r = 0, w = 0, b = 0;
        for ( int i = 0; i < nums.size(); i++ )
        {
            switch(nums[i])
            {
                case 0:
                    r++;
                    break;
                case 1:
                    w++;
                    break;
                case 2:
                    b++;
                    break;
                default :
                    cout << " a = " << nums[i] << endl;
                    
            }
        }
        nums.clear();
        while(r--)
            nums.push_back(0);
        while(w--)
            nums.push_back(1);
        while(b--)
            nums.push_back(2);      
    }
};

// This solutio is the well-known 3-way sorting algorithm, which uses three indices to partition the 
// array into three segments, i.e., lower part, middle part, and high part 
// Note that instead of checking equalities, we can use inequalities to partition to three ranges (vs three same values, color)
// The invariant is: 
// [0,r_top): are sorted (less then the middle)
// [w_top,b_bottom]: are to be checked, initially the whole array 
// (b_bottom,n-1]: are sorted (large than the middle)
// 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int r_top = 0, w_top = 0, b_bottom = nums.size() - 1;
        while ( w_top <= b_bottom )
        {
            if ( nums[w_top] == 0 )
            {
                swap(nums[w_top],nums[r_top]);
                w_top++;
                r_top++;
            }
            else if ( nums[w_top] == 2 ) 
            {
                swap(nums[w_top],nums[b_bottom]);
                b_bottom--;
            }
            else
            {
                w_top++;
            }
        }
    }
};

// This is a follow-up question which sort k colors 
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here   
        int lcolor = 1, highcolor = k;
        int sorted_last_pos = 0;
        int low_pos_unsorted = sorted_last_pos, high_pos_unsorted = colors.size() - 1; 
        while ( lcolor <= highcolor )
        {
            while( low_pos_unsorted <= high_pos_unsorted )
            {
                if ( colors[low_pos_unsorted] == lcolor )
                {
                    swap(colors[sorted_last_pos++],colors[low_pos_unsorted++]);
                }
                else if ( colors[low_pos_unsorted] == highcolor )
                {
                    swap ( colors[low_pos_unsorted],colors[high_pos_unsorted--] );
                }
                else 
                {
                    low_pos_unsorted++;
                }
            }
            low_pos_unsorted = sorted_last_pos - 1;
            lcolor++;
            highcolor--;
        }
    }
};