// Problem Description
/*
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.
*/

// idea: 
// this is an example of greedy alogrithm. To maximize the number of attended events, we could schedule events 
// as long as before their respective deadlines. Then for each event, we try to find a slot before its deadline. 
// If none day before its deadline can be found, then the event can't be attended. 
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events),end(events),[](const auto& a, const auto& b) {
             return a[1] < b[1];
             });
        int maxnumevents = 0;
        bool scheduled[100001] = { false };
        for ( const auto &e : events ) {
            for ( int i = e[0]; i <= e[1]; i++ ) {
                if ( !scheduled[i] ) {
                    scheduled[i] = true;
                    maxnumevents++;
                    break;
                }
            }
        }
        
        return maxnumevents;
    }
};