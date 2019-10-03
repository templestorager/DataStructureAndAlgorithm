// Problem Description
/*
    You have an array of logs.  Each log is a space delimited string of words.

    For each log, the first word in each log is an alphanumeric identifier.  Then, either:

    Each word after the identifier will consist only of lowercase letters, or;
    Each word after the identifier will consist only of digits.
    We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

    Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

    Return the final order of the logs.

    Example 1:

    Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    

    Constraints:

    0 <= logs.length <= 100
    3 <= logs[i].length <= 100
    logs[i] is guaranteed to have an identifier, and a word after the identifier.
 * 
 */

// We first partition the log such that all letter-logs are before the digit-only
// using stable_partition as we wanted to remain their order
// then we sort letter logs by customizing the pred condition
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>::iterator digit_logs = std::stable_partition(logs.begin(), logs.end(),
                                                                    [](const string log) { return isalpha(log.back());});
        sort(logs.begin(),digit_logs,LogCmp);
        return logs;
        
    }
    
    static bool LogCmp(const string first, const string second)
    {
        size_t spacepos1 = first.find(' ');
        size_t spacepos2 = second.find(' ');
        string word1 = first.substr( spacepos1 );
        string word2 = second.substr( spacepos2 );
        string identifier1 = first.substr(0,spacepos1);
        string identifier2 = second.substr(0,spacepos2);
        if ( word1 < word2 ) 
            return true;
        else if ( word1 == word2 ) {
            if ( identifier1 < identifier2 ) 
                return true;
            else 
                return false;
        }
        else {
            return false;
        }
    }
};