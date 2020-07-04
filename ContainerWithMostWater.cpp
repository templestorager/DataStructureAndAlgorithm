// Problem Description
/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
// This is the brute force solution that check every possible container
// O(n^2), O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for ( int i = 0; i < height.size(); i++ )
            for ( int j = i+1; j < height.size(); j++ )
            {
                maxarea = max( maxarea, min(height[i],height[j]) * (j-i) );
            }
        return maxarea;
    }
};

// This solution is based on the following intuition and the fact that the shorter bar decides the container capacity 
// We start from the container having the largest width, i.e., [0,size-1], which is potentially the biggest 
// container because it has the largest width 
// For the next container which coud be potentially larger than this one, it's only possibly realized by 
// increasing the height of the containter by dropping the shorter bar, given that the width is for sure to be 
// decremented by 1. 
// And this process is repeated, until the two bars meet. 
// O(n), O(1)

// Here is the non-strict math proof for "if we move the higher lines, we only get decreased area"
// Let's say, we have [Ai,Aj] as the container and Ai <= Aj. Therefore, height is Ai. 
// Say we move change Aj to Aj' and reduce width by 1. Then there are two case: 
// Ai <= Aj': the new height is Ai, the same as the original, but width is has decrased by 1. Thus, new area is reduced
// Ai > Aj' : the new height is Aj', and it's less than original height, plus width is reduced. Thus new area is reduced. 
// Therefore, we only need to consider change the lower line of the two points. 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int s = 0, e = height.size() - 1;
        while ( s < e )
        {
            maxarea = max( maxarea, min(height[e],height[s])*(e-s) );
            if ( height[s] < height[e] )
                s++;
            else
                e--;
        }
        
        return maxarea;
    }
};