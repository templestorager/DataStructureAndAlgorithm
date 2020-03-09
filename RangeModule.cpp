// Problem Description
/*
 A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.
*/


// This following method stores intervals as distinct intervals. 
// AddRange: check each stored interval 
//    (a) if the end of the current interval is less than the start of the new interval, we keep it as it is and increase the pos 
//    (b) if the start of the current interval is larger than the end of the new interval, we also keep it as it is but not increase 
//        the pos since the new interval comes after it 
//    (c) if the current interval overlaps the new interval, then we take the less of the starts and the larger of the ends to construct 
//        a new interval to be inserted at pos 
// QueryRange: check each stored interval and returns true if and only if there is one interval which can entirely covers the queried range
// RemoveRange: check each stored interval 
//    (a) if the end of the current interval is less than the start of the new interval, we keep it as it is and increase the pos 
//    (b) if the start of the current interval is larger than the end of the new interval, we also keep it as it is but not increase 
//        the pos since the new interval comes after it
class RangeModule {
public:
    RangeModule() {
        ranges.clear();
    }
    
    void addRange(int left, int right) {
        vector<pair<int,int>> res;
        int cur_sz = ranges.size(), pos = 0;
        for ( int i = 0; i < cur_sz; i++ ) 
        {
            if ( ranges[i].second < left ) 
            {
                res.push_back(ranges[i]);
                pos++;
            }
            else if ( ranges[i].first > right )
            {
                res.push_back(ranges[i]);
            }
            else 
            {
                left = min(left, ranges[i].first);
                right = max(right, ranges[i].second);
            }
        }
            res.insert(res.begin()+pos,{left,right});
            ranges = res;
    }
    
    bool queryRange(int left, int right) {
        for ( auto range : ranges ) 
        {
            if ( range.first <= left && range.second >= right )
                return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int,int>> res, tmp;
        int n = ranges.size(), pos = 0;
        for ( int i = 0; i < n; i++ )
        {
            if ( ranges[i].second <= left )
            {
                res.push_back(ranges[i]);
                pos++;
            }
            else if ( ranges[i].first >= right )
            {
                res.push_back(ranges[i]);
            }
            else 
            {
                if ( ranges[i].first < left ) 
                {
                    tmp.push_back({ranges[i].first,left});
                }
                if ( ranges[i].second > right )
                {
                    tmp.push_back({right, ranges[i].second});
                }
            }
        }
        res.insert(res.begin()+pos,tmp.begin(),tmp.end());
        ranges = res;
    }
private:
    vector<pair<int,int>> ranges;
};

// The following method has optimized search complexity as it internally maintains sorted intervals via
// leveraging the map data structure which maps starts to ends. 
// The key point it the abstracted find function shared by AddRange, QueryRange and RemoveRange
// The find function returns the pair that has no overlap with the existing intervals. Therefore: 
// For AddRange: it just sets up the new mapping in the map structure
// For RemoveRange: it checks whether the given ends intersects with any intervals or not. 
//                  if so, we need to add new intervals. 
class RangeModule {
public:
    RangeModule() {
        m.clear();
    }
    
    void addRange(int left, int right) {
        auto newrange = find(left,right);
        m[newrange.first] = newrange.second;
    }
    
    bool queryRange(int left, int right) {
        auto pos = m.upper_bound(left);
        return pos != m.begin() && (--pos)->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto pos = find(left, right);
        if ( left > pos.first )
            m[pos.first] = left;
        if ( pos.second > right )
            m[right] = pos.second;
    }
private:
    map<int,int> m;
    
    pair<int,int> find( int start, int end) {
        auto start_interval = m.upper_bound(start);  // the interval larger than given start 
        auto end_interval   = m.upper_bound(end);    // the interval larger than given end 
        if ( start_interval != m.begin() && (--start_interval)->second < start )  // check the start lies in the previous interval or in the gap 
            ++start_interval;   // The given start lies in the gap, then check where the end lies in 
        if ( start_interval == end_interval )  // the given end also lies in the gap, meaning there is no overlapping, then simply return 
            return {start,end};
        int new_start = min(start,start_interval->first);  // calculate new start: either start (in the gap) or the start of previous interval 
        int new_end   = max(end, (--end_interval)->second); // calculate new end: either end (in the gap) or the end of the interval containing the given end 
        m.erase(start_interval,++end_interval);
        return {new_start,new_end};
    }
};
