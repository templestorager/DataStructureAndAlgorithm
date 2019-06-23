#include <iostream>
#include <string> 
using namespace std;


int strStr(string haystack, string needle) 
{
        // using the Rabin-Karp algorithm 
        // 1. compute the hash feature of pattern (needle) 
        // 2. check the hash feature of each substring of haystack
        // 3. verify it's equal or not 
        // Chapter 32.2 of Introduction to Algorithms 
        // worst case O((n-m+1)m), preprocessing O(m)
        #define MODULUS 101
        #define RADIX   256   // the entire char set 
        int n = haystack.size();
        int m = needle.size();
        // handling needle is empty or m > n 
        long long h = 1;
        int p = 0;       // hash of pattern 
        int t = 0;      // hash of the substrings
        for( int i = 0; i < m; i++ )
        {
            p = ( RADIX * p + needle[i] ) % MODULUS;
            t = ( RADIX * t + haystack[i] ) % MODULUS;
        }

        for( int i = 0; i < m - 1; i ++ ) 
            h = ( h * RADIX ) % MODULUS;
        
        for( int s = 0; s < n-m+1; s++ ){
            if( p == t ){
                if( needle.compare(haystack.substr(s,m)) == 0 )
                    return s;
            }
            if ( s < n-m ){
                t = ( RADIX * (t-haystack[s]*h)+haystack[s+m] ) % MODULUS;
            }
            if ( t < 0 )
                t += MODULUS;
       }
        return -1;
}

int main()
{
    string haystack("hello");
    string needle("ll");
    int shift = strStr(haystack,needle);

    cout<<"haystack is "<<haystack<<" and needle is "<<needle<<endl;
    cout<<" The first valid shift is "<< shift << endl;

}