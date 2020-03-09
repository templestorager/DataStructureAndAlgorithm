// Problem Description 
/*
 Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/


// Idea: sort the intervals and then check each of the intervals for overlapping 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
    
        if ( n <= 1 )
            return intervals;
        
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        res.push_back(intervals[0]);
        for ( int i = 1; i < n; i++ )
        {
            if ( intervals[i][0] > res.back()[1] )
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        
        return res;
    }
};


// This following method leverages the fact that the property doesn't change if we were given the 
// intervals consisting of respective sorted starts and ends. 
// Basically it means, we merge intervals in the order of given sorted pairs. Therefore, whenever 
// we encounter a start larger than an end, we insert a new interval. 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        vector<int> starts, ends;
        
        for ( int i = 0; i < n; i++ )
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        
        for ( int i = 0, j = 0; i < n; i++ )
        {
            if ( i == n - 1 || starts[i + 1 ] > ends[i] ){
                res.push_back({starts[j],ends[i]});
                j = i+1;
            }
        }
        
        return res;
    }
};