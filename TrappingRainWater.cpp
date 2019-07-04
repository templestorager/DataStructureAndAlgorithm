// Problem Description 
/*
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 */


// This solution is based on the following intuition: 
// The amount of water each bar holds is the difference between the min of the left highest and 
// right hightest and the height itself if the min is larger. 
// O(n^2), O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int TotalWater = 0, MaxLeft, MaxRight;

        for ( int i = 1; i < height.size(); i++ ) {
            int localwater = 0, MaxLeft = 0, MaxRight = 0;
            for ( int left = 0; left < i; left++ ) {
                if ( height[left] > MaxLeft )
                    MaxLeft = height[left];
            }
            
            for ( int right = i + 1; right  < height.size(); right++ ) {
                if ( height[right] > MaxRight )
                    MaxRight = height[right];
            }
            
            if ( min(MaxLeft, MaxRight) > height[i] )
                localwater = min( MaxLeft, MaxRight ) - height[i];
            TotalWater += localwater;
        }
        
        return TotalWater;
    }
};

// This solution improves over the above solution through dynamical programming by remembering the 
// left max and right max of each element so as to avoid repeated iterations to find the maxs
// O(n), Two iterations, O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int TotalWater = 0;
        if ( height.size() == 0 )
            return 0;
        int barnum = height.size();
        
        vector<int> left_max(barnum), right_max(barnum);
        left_max[0] = height[0];
        right_max[barnum-1] = height[barnum-1];
        
        for ( int left = 1; left < barnum; left++ ) {
            left_max[left] = max(left_max[left - 1], height[left]);
        }
        
        for ( int right = barnum - 2; right >= 0; right-- ) {
            right_max[right] = max(right_max[right+1],height[right]);
        }
        
        for ( int bar = 1; bar < barnum; bar++ ) {
            TotalWater += min(left_max[bar],right_max[bar]) - height[bar];
        }
        
        return TotalWater;
    }
};

// This solution is essentially the same as the above one, except that it uses one array to store 
// the max values by checking the min height during the second scan. 
// O(n), two interations,  O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int TotalWater = 0, curmax = 0;
        if ( height.size() == 0 )
            return 0;
        int barnum = height.size();
        
        vector<int> maxheight(barnum,0);
        
        for ( int left = 0; left < barnum; left++ ) {
            maxheight[left] = curmax; 
            curmax = max(height[left],curmax);
        }
        
        curmax = 0; 
        
        for ( int right = barnum - 1; right >= 0; right-- ) {
            maxheight[right] = min(curmax, maxheight[right]);
            curmax = max(curmax,height[right]);
            if ( maxheight[right] > height[right] )
                TotalWater += ( maxheight[right] - height[right] );
            
        }
        
        return TotalWater;
    }
};

// The following two solutions use stack to calcluate trapped waters. 
// As it iterates through the array, the stack top acts as the left bound, and the current 
// element acts as the right bound if it is larger than top element. If it is smaller than 
// the top then it's pushed onto the stack, as it could potentially contain trapped water. 
// the following figure shows an example using the stack method. It traps a total of 10 units 
// of water and (A,B,C,D,E) are the areas of its' calculation order
// O(n), O(n)

/* 
 *
 *           C(4)      __  E(2)
 *    __ /         \__|__|/    \__
 *   |__|   __     |__|__|   __|__|
 * __|__|__|__|____|__|__|__|__|__|
 *       \/    \  /      \  /
 *       A(1)   B(2)     D(1)
 * 0 |1 |2 |3 |4 5 |6 | 7|8 |9 |10|    // index 
 * 0  2  0  1  0  0  2  3  0  1  2     // height array  
 * 
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int TotalWater = 0, current_idx = 0; 
        stack<int> barstack;
        while( current_idx < height.size() ) {
            while ( !barstack.empty() && height[current_idx] > height[barstack.top()] ) {
                int top = barstack.top();
                barstack.pop();
                if ( barstack.empty() )
                    break;            
                int length = current_idx - barstack.top() - 1;
                int bounded_height = min( height[current_idx], height[barstack.top()]) - height[top];
                TotalWater += length * bounded_height;
            }
            
            barstack.push(current_idx++);
        }
        return TotalWater;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> bounds;
        int bar = 0, res = 0, barnum = height.size();
        while (bar < barnum) {
            if (bounds.empty() || height[bar] <= height[bounds.top()]) {
                bounds.push(bar++);
            } else {
                int top = bounds.top(); 
                bounds.pop();
                if (bounds.empty()) 
                    continue;
                res += (min(height[bar], height[bounds.top()]) - height[top]) * (bar - bounds.top() - 1);
            }
        }
        return res;
    }
};

// This solution use two pointers to check the trapped water for each bar 
// O(n), single iteration, O(1)
class Solution {
public:
    int trap(vector<int>& height) { 
        int left = 0, right = height.size() - 1;
        int TotalWater = 0;
        int left_max = 0, right_max = 0;
        while ( left < right ) {
            if ( height[left] < height[right] ) {
                height[left] >= left_max ? ( left_max = height[left]) : 
                TotalWater += ( left_max - height[left] );
                left++;
            }
            else {
                height[right] >= right_max ? ( right_max = height[right] ) : 
                TotalWater += ( right_max - height[right] );
                right--;
            }
        }
        
        return TotalWater;
    }
};