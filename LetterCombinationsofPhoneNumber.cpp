// Problem Description 

/*
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
 * the number could represent. A mapping of digit to letters (just like on the telephone buttons) is 
 * given below. Note that 1 does not map to any letters.
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *  
 */
// this solution uses backtracking (recursive) method 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<string,string> nummap; 
        vector<string> res;
        
        // initialize the nummap
        nummap.emplace("2","abc");
        nummap.emplace("3","def");
        nummap.emplace("4","ghi");
        nummap.emplace("5","jkl");
        nummap.emplace("6","mno");
        nummap.emplace("7","pqrs");
        nummap.emplace("8","tuv");
        nummap.emplace("9","wxyz");
        if ( digits.size() != 0 ) {
            backtrack("",digits,nummap,res);
        }
        
        return res;
    }
    
    void backtrack(string currentres, string next_digits, map<string,string> nummap, vector<string> &res) {
        if ( next_digits.size() == 0 ) {
            res.push_back(currentres);
        }
        else {
            string nextdigit = next_digits.substr(0,1);
            string nextletters = nummap[nextdigit];
            for ( int i = 0; i < nextletters.size(); i++ ) {
                string nextletter = nextletters.substr(i,1);
                backtrack(currentres+nextletter,next_digits.substr(1),nummap,res);
            }
        }
    }
};

// this solution uses iterative idea 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if ( digits.size() == 0 ) 
            return {};
        vector<string> res{""};
        vector<string> phonemapping{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for( int i = 0; i < digits.size(); i++ ) {
            vector<string> tempres;
            string letters = phonemapping[digits[i]-'0'];
            for( int j = 0; j < letters.size(); j++ ) {
                for ( string s : res )
                    tempres.push_back(s+letters[j]);
            }
            res = tempres;
        }
        return res;
    }
};