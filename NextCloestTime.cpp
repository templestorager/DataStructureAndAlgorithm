// Problem Description
/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

// construct all possible combinations and then check each difference 
class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> digits;
        int min_elapsed = 24 * 60;
        int h_res, m_res;
        int delimiter_pos = time.find(":");
        int cur_time = stoi(time.substr(0,delimiter_pos)) * 60 + stoi(time.substr(delimiter_pos+1));
        h_res = stoi(time.substr(0,delimiter_pos));     // handle the case 00:00
        m_res = stoi(time.substr(delimiter_pos+1));     // handle the case 00:00
        string res;
        for ( auto c : time )
        {
            if ( c != ':' )
                digits.insert(c-'0');      // at most four digits 
        }
        
        for ( auto h1 : digits )
            for ( auto h2 : digits )
            {
                int hour = h1 * 10 + h2;
                if ( hour < 24 )
                {
                    for ( auto m1 : digits ) 
                        for ( auto m2 : digits )
                        {
                            int minute = m1 * 10 + m2;
                            if ( minute < 60 )
                            {
                                int candi_elapsed = hour * 60 + minute - cur_time;
                                if ( candi_elapsed < 0 )
                                    candi_elapsed += 24 * 60;
                                if ( candi_elapsed > 0 && candi_elapsed < min_elapsed )
                                {
                                    min_elapsed = candi_elapsed;
                                    h_res = hour;
                                    m_res = minute;
                                }
                            }
                        }
                }
            }
        
        res += h_res >= 10 ? to_string(h_res) : ("0"+to_string(h_res));
        res += ":";
        res += m_res >= 10 ? to_string(m_res) : ("0" + to_string(m_res));
        return res;
    }

};