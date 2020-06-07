// Problem Description 

/*
 *
 * Remove the minimum number of invalid parentheses in order to make the input string valid. 
 * Return all possible results.
 * Note: The input string may contain letters other than the parentheses ( and ).
 * 
 * Example 1:
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * Example 2:
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * Example 3:
 * Input: ")("
 * Output: [""]
 * 
 * */

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> st;     // use set to store and remove duplicate results 
        vector<string> res;     // this is the final result set, which is inited with the resultant set
        string expression;      // the current expression with removals, it is subsequence of the given string 
        int min_removed = INT_MAX;
        removeInvalidHelper(s,0,expression,0,0,st,0,min_removed);
        res.assign(st.begin(),st.end());
        return res;
    }
    void removeInvalidHelper( const string &s, int curidx, string &curexpression, int openCnt, int closeCnt, set<string> &res, int removedCnt, int &min_removed )
    {
        // if we are at the end of the string 
        if ( curidx == s.size() )
        {
            // if the current expression is valid 
            if ( openCnt == closeCnt )
            {
                // if the current count of removed is <= the current minimum count 
                if ( removedCnt <= min_removed )
                {
                    if ( removedCnt < min_removed )
                    {
                        // if we find a new mini removal 
                        res.clear();
                        min_removed = removedCnt;
                    }
                    res.insert(curexpression);
                }
            }
        }
        // We are processing middle chars 
        else 
        {
            char curch = s[curidx];
            int  curlen = curexpression.length();
            if ( curch != '(' && curch != ')' )
            {
                curexpression.push_back(curch);
                removeInvalidHelper( s, curidx+1, curexpression, openCnt, closeCnt, res, removedCnt, min_removed);
                // why do we need to unpush a regular char ? 
                // because we need to change the choice of parenthese before this regular char 
                // curexpression.pop_back();
                curexpression = curexpression.substr(0,curlen);
            }
            else 
            {                           
                // if it is either '(' or ')', then we can remove it and recurse further                     
                removeInvalidHelper(s,curidx+1,curexpression,openCnt,closeCnt,res,removedCnt+1,min_removed);
                // or we can choose to not remove it, i.e., keep it and then recursive further 
                curexpression.push_back( curch );
                if ( curch == '(' )
                {
                    removeInvalidHelper(s,curidx+1,curexpression,openCnt+1,closeCnt,res,removedCnt,min_removed);
                } 
                else if ( closeCnt < openCnt )
                {
                    removeInvalidHelper( s, curidx+1, curexpression, openCnt, closeCnt+1, res, removedCnt, min_removed);
                }
                // similarly we backtrack the just pushed-back char 
                //curexpression.pop_back();
                curexpression = curexpression.substr(0,curlen);
            }
        }
    }
};

// The same idea and procedure, but written in another way 
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        min_removed = INT_MAX;
        vector<string> res;
        st.clear();
        string curres; 
        helper(s,curres,0,0,0,0);
        res.assign(st.begin(),st.end());
        return res;
    }
private:
    set<string> st;     // may contain duplicates 
    int min_removed;  
    void helper( const string &s, string &curres, int openCnt, int closeCnt, int curIdx, int cur_removed )
    {
        if ( curIdx  == s.size() )
        {
            if ( openCnt == closeCnt )
            {
                if ( cur_removed <= min_removed )
                {
                    if ( cur_removed < min_removed )
                    {
                        min_removed = cur_removed;
                        st.clear();
                    }
                    st.insert(curres);
                }
            }
        }
        else 
        {
            char curch = s[curIdx];
            if ( curch != '(' && curch != ')' )
            {
                curres.push_back(curch);
                helper(s,curres,openCnt,closeCnt,curIdx+1,cur_removed);
                curres.pop_back();
            }
            else
            {
                helper(s,curres,openCnt,closeCnt,curIdx+1,cur_removed+1);
                curres.push_back(curch);
                if ( curch == '(' )
                {
                    
                    helper(s,curres,openCnt+1,closeCnt,curIdx+1,cur_removed);
                }
                else if ( curch == ')' && openCnt > closeCnt )
                {
                    helper(s,curres,openCnt,closeCnt+1,curIdx+1,cur_removed);
                }
                curres.pop_back();
            }
        }
    }
};

// The above solution is based on DFS, and this solution is based on BFS. 
// Here a step in the breath means the number of removals, starting from 0 removals to the len of the string 
// The queue holds the strings with the same number of (current) removals. 
// Then if we ever find any string in the curent queue is valid, then it means the current string has the minimal 
// removals. Remember we are BFSing based on the removals. If ever found, we just push all the valid strings in the 
// queue to the result. 
// Note: while we try to remove a parenthese, we might encounter a string which has appeared before. 
// Therefore, we use a set to avoid duplicate strings being pushed to the queue again. 
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        set<string> visited;
        queue<string> remove_step_str;
        remove_step_str.push(s);
        bool found_step = false;
        while ( !remove_step_str.empty() )
        {
            string tmp = remove_step_str.front();
            remove_step_str.pop();
            if ( IsValid(tmp) )
            {
                res.push_back(tmp);
                found_step = true;
            }
            if ( found_step )
                continue;
            for ( int i = 0; i < tmp.size(); i++ )
            {
                if ( tmp[i] == '(' || tmp[i] == ')' )
                {
                    string next = tmp.substr(0,i) + tmp.substr(i+1);
                    if ( !visited.count(next) )
                    {
                        remove_step_str.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        
        return res;
    }
    
    bool IsValid( const string s )
    {
        int cnt = 0; 
        for ( auto c : s )
        {
            if ( c == '(' )
                cnt++;
            else if ( c == ')' && --cnt < 0 )
                return false;
        }
        
        return cnt == 0;
    }
};

// This solution first calculates how many left and right (parenthese) are needed to be removed 
// Then it tries to removed them as it recurses down the string. 
// The end condition is when both left and right are zeros.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left, right;
        FindInvalidParentheses( s, left, right );
        helper(s,0,left,right,res);
        return res;
    }
    
    void helper( string s, int start, int left, int right, vector<string>& res )
    {
        if ( left == 0 && right == 0 )
        {
            if ( IsValid(s) )
                res.push_back( s );
            return;
        }
        
        for ( int i = start; i < s.size(); i++ )
        {
            if ( i != start && s[i] == s[i-1] ) // this handles the duplicate resulting from consecutive parentheses. e.g., remove either '(' in "(()" is the same 
                continue;
            if ( left > 0 && s[i] == '(' )
                helper( s.substr(0,i) + s.substr(i+1), i, left-1, right, res );
            if ( right > 0 && s[i] == ')' )
                helper( s.substr(0,i) + s.substr(i+1), i, left, right-1, res );
        }
    }
    
    void FindInvalidParentheses( const string s, int &left, int &right )
    {
        int left_ = 0, right_ = 0;
        for ( auto c : s )
        {
            if ( c == '(' )
                left_++;
            else if ( left_ == 0 )
                right_ += (c == ')');
            else 
                left_ -= ( c == ')' );
        }
        
        left = left_;
        right = right_;
    }
    
    bool IsValid( const string s )
    {
        int cnt = 0; 
        for ( auto c : s )
        {
            if ( c == '(' )
                cnt++;
            else if ( c == ')' && --cnt < 0 )
                return false;
        }
        
        return cnt == 0;
    }
};



class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper( s, 0, 0, {'(',')'},res);
        return res;
    }
    
    void helper( string s, int last_i, int last_j, vector<char> p, vector<string> &res )
    {
        int cnt = 0;
        for ( int i = last_i; i < s.size(); i++ )
        {
            if ( s[i] == p[0] )
                cnt++;
            else if ( s[i] == p[1] )
                cnt--;
            if ( cnt >= 0 )
                continue;
            for ( int j = last_j; j <= i; j++ )
            {
                if ( s[j] == p[1] && (j == last_j || s[j] != s[j-1] ) )
                    helper( s.substr(0,j) + s.substr(j+1), i,j,p,res);
            }
            return;
        }
        string rev = string(s.rbegin(),s.rend());
        if ( p[0] == '(' )
            helper(rev,0,0,{')','('},res);
        else
            res.push_back(rev);
    }
};