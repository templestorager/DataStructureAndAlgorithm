// Problem Description
/*
 Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/

// Leap-year: evenly divisible by 400 or evenly divisible by 4 but not by 100 
class Solution {
public:
    int dayOfYear(string date) {
        int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // non-leap year days, need to increment by 1 for leap year
        int days = 0, year, month, day;
        bool leap_year = false;
        year  = stoi(date.substr(0,4));
        month = stoi(date.substr(5,2));
        day   = stoi(date.substr(8,2));
        
        leap_year = (year % 400 == 0) || (year % 100 && year % 4 == 0 );
        
        for ( int i = 0; i < month; i++ ) 
        {
            days += days_month[i];
        }
        
        days += day;
        if ( leap_year && month > 2 )
            days++;
        return days;
    }
};