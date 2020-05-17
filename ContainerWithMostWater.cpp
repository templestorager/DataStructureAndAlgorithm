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

// This solution is based on the following intuition and the fact that the shorted bar decides the container capacity 
// We start from the container having the larget width, i.e., [0,size-1], which is potentially the biggest 
// container because it has the largest width 
// For the next container which coud be potentially larger than this one, it's only possibly realized by 
// increase the height of the containter by dropping the shorter bar, given that the width is for sure to be 
// decremented by 1. 
// And this process is repeated, until the two bars meet. 
// O(n), O(1)
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