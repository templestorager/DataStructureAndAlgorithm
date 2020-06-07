// Problem Description 
/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

 

Example 1:


Input: graph = [
  [1,1,0],
  [0,1,0],
  [1,1,1]
]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
Example 2:


Input: graph = [
  [1,0,1],
  [1,1,0],
  [0,1,1]
]
Output: -1
Explanation: There is no celebrity.
 

Note:

The directed graph is represented as an adjacency matrix, which is an n x n matrix where a[i][j] = 1 means person i knows person j while a[i][j] = 0 means the contrary.
Remember that you won't have direct access to the adjacency matrix.
*/

/*
class Solution {
public:
    int findCelebrity(int n) {
        bool know[n][n];
        bool visited[n][n];
        memset( visited,false,sizeof(visited) );
        memset(know,false,sizeof(know));
        int i, j;
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( visited[j][i] )
                {
                    if ( !know[j][i] )
                        break;
                }
                else 
                {
                    visited[j][i] = true;
                    if ( knows(j,i) )
                    {
                        know[j][i] = true;
                    }
                    else 
                    {
                        know[j][i] = false;
                        break;
                    }
                }
                if ( visited[i][j] )
                {
                    if ( know[i][j] )
                        break;
                }
                else 
                {
                    visited[i][j] = true;
                    if ( knows(i,j) )
                    {
                        know[i][j] = true;
                        break;
                    }
                    else 
                    {
                        know[i][j] = false;
                    }
                }
            }
            if ( j == n )
                return i;
        }
        
        return -1;
    }
};
*/


// This is the brute force solution, which checks each people whether it is a celebrity or not 

class Solution {
public:
    int findCelebrity(int n) {
        for ( int i = 0; i < n; i++ )
            if ( IsCelebrity(i,n) )
                return i;
        return -1;
    }
    
    bool IsCelebrity(int i, const int n) 
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( i == j )
                continue;
            if ( knows(i,j) || !knows(j,i) )
                return false;
        }
        return true;
    }
};

// This solution improves on the above solution by first narrowing down the candidate to one based on the following 
// observations/insights 
// for each call knows(i,j), we can exclude one. So if we call it n-1 times, then we can excludes n-1 persons 
// specifically: 
// if knows(i,j) returns true, then i CANN'T be the celebrity, because he/she knows j
// if knows(i,j) returns false, then j CANN'T be the celebrity, because i DOESN'T know him/her 
class Solution {
public:
    int findCelebrity(int n) {
        // we only need to call at most n-1 knows, as each call disqualifies one person 
        int candidate = 0;
        for ( int i = 1; i < n; i++ )
        {
            if ( knows(candidate, i) )
            {
                // since candidate knows i, so candidate cann't be the celebrity 
                candidate = i;
            }
            else 
            {
                // because candidate doesn't know i, so i can never be a candidate 
            }
        }
        if ( IsCelebrity(candidate,n) )
            return candidate;
        return -1;
    }
    
    bool IsCelebrity( int j, const int n )
    {
        for ( int i = 0; i < n; i++ )
        {
            if ( i == j )
                continue;
            if ( !knows(i,j) || knows(j,i) )
                return false;
        }
        return true;
    }
};

// This solution adds an opitmization to the above solution by avoiding some calls to knows 
// The first step is the same, i.e., finding a candidate
// The second step is to validate the candidate. 
// for the first part before the candidate, we need to check that candidate knows nobody while everybody knows the candidate 
// for the second part after the candidate, we just need to check that every knows the candidate, because we are guaranteed 
// the candidate doesn't know anybody, otherwise he/she cann't be the candidate
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0; 
        for ( int i = 1; i < n; i++ )
            if ( knows(candidate,i) )
                candidate = i;
        for ( int i = 0; i < candidate; i++ )
            if ( !knows(i,candidate) || knows(candidate, i) )
                return -1;
        for ( int i = candidate + 1; i < n; i++ )
            if ( !knows(i,candidate) )
                return -1;
        return candidate;
    }
};