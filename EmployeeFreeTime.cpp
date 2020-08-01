// Problem Description 
/*
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

 

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 

Constraints:

1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8
*/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

// One way of thinking about this problem is that we can merge all intervals to simulate all occupied time intervals 
// Then the common free intervals will be all discontinued intervals after the merging, excluding time before the smallest 
// start time and after the largest end time. 
// O(ClogC), O(C)
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res, all_intervals;
        for ( auto e : schedule )
            all_intervals.insert( all_intervals.end(), e.begin(),e.end());
        sort( all_intervals.begin(), all_intervals.end(),[](Interval &a, Interval &b) { return a.start < b.start;});
        Interval cur = all_intervals[0];
        for ( int i = 1; i < all_intervals.size(); i++ )
        {
            Interval next = all_intervals[i];
            if ( cur.end < next.start )
            {
                res.push_back( Interval(cur.end,next.start));
                cur = next;
            }
            else 
            {
               // cur.end = cur.end > next.end ? cur.end : next.end;
                cur = cur.end > next.end ?  cur : next;
            }
        }
        
        return res;
    }
};

// We use a map to record the occurrence of every timepoint. For starting time, we increment by one and for 
// end time, we decrease by one. Then we walk through all the timepoints and maintain a running accumulative 
// total credit balance. Whenever the balance becomes zero, we encounter a timepoint where no interval overlaps 
// it. It's only possible that an end time would cause the balance to be zero. We then temporarily push an Interval 
// with end being 0 to the result, and then update it if we have more intervals being added or delete it if it is the last one. 

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        int balance = 0;
        map<int, int> m;
        for ( auto e : schedule )
        {
            for ( auto I : e )
            {
                m[I.start]++;
                m[I.end]--;
            }
        }
        
        for ( auto it = m.begin(); it != m.end(); it++ )
        {
            balance += it->second; 
            if ( balance == 0 )
            {
                res.push_back(Interval(it->first,0));
            }
            else if ( !res.empty() && !res.back().end )
            {
                res.back().end = it->first;
            }
        }
        
        res.pop_back();
        return res;
    }
};