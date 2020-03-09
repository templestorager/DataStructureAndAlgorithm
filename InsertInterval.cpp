// Problem Description
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

// This solution uses a temporary storage while examining each of the existing intervals. 
// The key is to construct a new interval (could be alone, or as a result of overlapping) and remember the post for it to be inserted

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int new_start = newInterval[0], new_end=newInterval[1];
        int n = intervals.size();
        int pos = 0; 
        for ( int i = 0; i < n; i++ ) 
        {
            if ( intervals[i][0] > newInterval[1] )
                res.push_back(intervals[i]);
            else if (intervals[i][1] < newInterval[0] )
            {
                res.push_back(intervals[i]);
                pos++;
            }
            else
            {
                new_start = min(new_start, intervals[i][0]);
                new_end   = max(new_end, intervals[i][1]);
            }

        }
        res.insert(res.begin()+pos, {new_start,new_end});
        return res;
    }
};


// This solution is esentially the same as the above one, but is more straightforward in  displaying 
// the three steps: process any intervals before the new interval, process overlapped intervals, and 
// process any intervals after the new interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), cur = 0;
        while ( cur < n && intervals[cur][1] < newInterval[0] ) 
        {
            res.push_back(intervals[cur++]);
        }
        while ( cur < n && intervals[cur][0] <= newInterval[1] ) 
        {
            newInterval[0] = min(newInterval[0],intervals[cur][0]);
            newInterval[1] = max(newInterval[1],intervals[cur][1]);
            cur++;
        }
        res.push_back(newInterval);
        while ( cur < n )
        {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};