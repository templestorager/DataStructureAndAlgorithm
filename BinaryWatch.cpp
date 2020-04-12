// Problem Description 
/*
 A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
 */

// This method considers all possible timepionts and check each point if it the said number of 1s
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for ( int h = 0; h < 12; h++ )
            for ( int m = 0; m < 60; m++ )
            {
                if ( bitset<10>((h << 6) + m).count() == num )
                {
                    res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        return res;
    }
};