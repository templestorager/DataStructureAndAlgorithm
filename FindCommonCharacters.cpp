// Problem Description 
/*
    Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
    You may return the answer in any order.
    Example 1:

    Input: ["bella","label","roller"]
    Output: ["e","l","l"]
    Example 2:

    Input: ["cool","lock","cook"]
    Output: ["c","o"]
 * 
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for ( char ch = 'a'; ch <= 'z'; ch++ ) {
            int min_num = INT_MAX;
            for ( int i = 0; i < A.size(); i++ ) {
                int num = FindOccurence(ch,A[i]);
                if ( num < min_num ) {
                    min_num = num;
                }
            }
            if ( min_num != 0 ) {
                while (min_num--)
                    res.push_back(string(1,ch));
            }   
        }
        
        return res;
    }
    
private:
    int FindOccurence(const char ch, const string s)
    {
        int result = 0;
        size_t pos = 0, tmp;
        while ( (tmp = s.find(ch,pos)) != string::npos ) {
        //for ( auto c : s ){
            //if ( c == ch)
                pos = tmp+1;
                result++;
        }
        
        return result;
    }
};