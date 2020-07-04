// Problem description 
/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

// This is common application of DSF algorithm
// If the current result is a valid result, then record in the result set. 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curres; 
        helper(res,n,k,1,curres);
        return res;
    }
    
    void helper(vector<vector<int>>& res, const int n, const int sz, int curnum, vector<int>& comb )
    {
        if(comb.size() == sz)
        {
            res.push_back(comb);
            return;
        }
        for ( int i = curnum; i <= n; i++ )
        {
            comb.push_back(i);
            helper(res,n,sz,i+1,comb);
            comb.pop_back();
        }
    }
};

// This idea uses the combinatoric equation C(n,k) = C(n-1,k-1) + C(n-1,k) and recursion 
// The equation can be intepreted as: to select k numbers out of n numbers, we have two scenarios:
//  (1). We assume a fixed number is already selected (n), then we need to select 
//       the remaining k-1 out of (n-1) numbers, whose amount is C(n-1,k-1)
//  (2). We assume all the combination does not include that fixed number, then we need to select 
//       the entire k numbers out of the remaining (n-1) numebrs, whose amount is C(n-1,k); 
// As we reduce the number, we can go down to the base case, where k is zero and the result is an empty set, 
// implying we could use recursion. 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if ( n < k || k < 0 )
            return {};
        if ( k == 0 )
            return {{}};        // the base case 
        vector<vector<int>> res = combine(n-1,k-1); // the amount of the first case 
        for ( auto &a : res )
            a.push_back(n);         // as it lacks the fixed number (n), we should put it back for every combination in the first case 
        for ( auto a : combine(n-1,k) )     // for each combination in the second case, we just add it in the result set
            res.push_back(a);
        return res;
    }
};

// This method generates the combination numbers in the increasing(value) order. 
// Numbers at the right side have larger values. 
// For the current number, we first increase it by one, and then check the following conditions (must be the order)
// 1. check whether the value reaches maximum or not. If it exceeds the maximum, which means we have completed processing 
//    this position as the right-most position. we need to move the left value, which will then reset its value to the 
//    the left value plus one
// 2. check whether we have a combination, if so we store the result
// 3. we move to increase the next number 
// Take the n = 5, k = 3 for example, the order would be like this: 
// [1,2,3],[1,2,4],[1,2,5],[1,3,4],[1,3,5],[1,4,5],[2,3,4],[2,3,5],[2,4,5],[3,4,5]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp(k,0);
        int i = 0;
        while ( i >= 0 )
        {
            tmp[i]++;
            if( tmp[i] > n )
                --i;                // Step3: this will be executed as a backtracking
            else if ( i == k-1 )
                res.push_back(tmp);  // Step2: will be excuted to record one result 
            else
            {               // Step1: This block will be excuted first 
                i++;
                tmp[i] = tmp[i-1];
            }

        }
        return res;
    }
};

// this method is based on a mysterious algorithm, which I don't understand yet :-) 
// Seems to be like this
// init an array [1...k, n+1]
// check the array starting from the begining, if the current is consecutive to the next, then reset its value to 
// to its rank (i.e., position idx plus one)
// otherwise increases the value by one and continue to the next loop
// for example: n = 4, k = 2;
// [1,2,5]  -- > [1,2]
// [1,3,5]  -- > [1,3]
// [2,3,5]  -- > [2,3]
// [1,4,5]  -- > [1,4]
// [2,4,5]  -- > [2,4]
// [3,4,5]  -- > [3,4]
// Done. 

// for example: n = 5, k = 3
// [1,2,3,6] --> [1,2,3]
// [1,2,4,6] --> [1,2,4]
// [1,3,4,6] --> [1,3,4]
// [2,3,4,6] --> [2,3,4]
// [1,2,5,6] --> [1,2,5]
// [1,3,5,6] --> [1,3,5]
// [2,3,5,6] --> [2,3,5]
// [1,4,5,6] --> [1,4,5]
// [2,4,5,6] --> [2,4,5]
// [3,4,5,6] --> [3,4,5]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        for ( int i = 1; i <=k; i++ )
            tmp.push_back(i);
        tmp.push_back(n+1);
        int j = 0; 
        while ( j < k )
        {
            res.push_back(vector<int>(tmp.begin(),tmp.end()-1));
            j = 0;
            while ( j < k && tmp[j+1] == tmp[j] + 1 )
            {
                tmp[j] = j+1;
                j++;
            }
            tmp[j]++;
        }
        
        return res;
    }
    
};