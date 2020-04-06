// Problem Description 
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

// Idea: there are three possibilities 
// 1. there is a cycle (not a happy number)
// 2. it comes down to 1 (a happy number)
// 3. infinity steps (i.e., requires infinite space to detect cycle)
// Note: we claim that the third case is impossible, as the biggest number (9....9) would go down to a much smaller number 

// This method is recursive version 
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        return isHappyHelper(s,n);
    }
    bool isHappyHelper(unordered_set<int> &s, int n )
    {
        if ( s.count(n) )
            return false;
        int sum = 0;
        s.insert(n);
        while(n)
        {
            sum += (n%10) *(n%10);
            n /= 10;
        }
        
        if ( sum == 1 )
            return true;
        return isHappyHelper(s,sum);
    }
};

// we can also write its iterative vesion 
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while ( n != 1 && s.count(n) == 0 )
        {
            s.insert(n);
            n = GetNext(n);
        }
        return n == 1;
    }
    int GetNext(int n)
    {
        int sum = 0; 
        while (n)
        {
            sum += (n%10) *(n%10);
            n /= 10;
        }
        
        return sum;
    }
};

// This method is essentially the same as the above method, but it is based on math analysis 
// which demonstrates that cycle can only happen to number less than 243 and there is only one chain
// other numbers with lead to 1 or at some point enters this only cycle
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cyclechain{4,16,37,58,89,145,42,20};
        while ( n != 1 && !cyclechain.count(n) )
        {
            n = GetNext(n);
        }
        
        return n == 1;
    }
    int GetNext(int n)
    {
        int sum = 0; 
        while (n)
        {
            sum += (n%10) *(n%10);
            n /= 10;
        }
        
        return sum;
    }
};

// The problem can be converted to detect the existence of a cycle, with which we can deal using "two pointer" method
// if there is a cycle (not a happy number), then the fast will finally catch the slow 
// if there is no cycle (happy number), then the fast will first go down to 1
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = GetNext(n);
        while ( fast != 1 && fast != slow )
        {
            slow = GetNext(slow);
            fast = GetNext(GetNext(fast));
        }
        return fast == 1;
    }
    int GetNext(int n)
    {
        int sum = 0; 
        while (n)
        {
            sum += (n%10) *(n%10);
            n /= 10;
        }
        
        return sum;
    }
};