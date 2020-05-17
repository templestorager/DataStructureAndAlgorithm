// Problem Description
/*
 Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
// Be sure to check the most restrictive conditions first
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        vector<string> fizzBuzzstrs = {"Fizz","Buzz","FizzBuzz"};
        for ( int i = 1; i <= n; i++ )
        {
            if ( i % 3 == 0 && i % 5 == 0 )
            {
                res.push_back(fizzBuzzstrs[2]);
            }
            else if ( i % 3 == 0 )
            {
                res.push_back(fizzBuzzstrs[0]);
            }
            else if ( i % 5 == 0 )
            {
                res.push_back(fizzBuzzstrs[1]);
            }
            else 
            {
                res.push_back(to_string(i));
            }     
        }
        
        return res;
    }
};

// This solution doesn't improve the asymptotic complexit, yet the idea of cancatenation 
// provides better flexibility when the conditions needing to be checked increase
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        vector<string> fizzBuzzstrs = {"Fizz","Buzz"};
        for ( int i = 1; i <= n; i++ )
        {
            string s;
            if ( i % 3 == 0 )
                s += fizzBuzzstrs[0];
            if ( i % 5 == 0 )
                s += fizzBuzzstrs[1];
            if ( s == "" )
                s += to_string(i);
            res.push_back(s);
        }
        
        return res;
    }
};

// This method provides even better flexibility by storing the condition in a hash set
// One thing worth noting is that, we need to make sure it's sorted if we use iterators to traverse
// the map. Therefore, we use map structure 
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        map<int,string> rules = 
        {
            {3,"Fizz"},
            {5,"Buzz"}
        };
        for ( int i = 1; i <= n; i++ )
        {
            string s;
            for ( auto iter = rules.begin(); iter != rules.end(); iter++ )
            {
                if ( i % iter->first == 0 )
                    s += iter->second;
            }
            if ( s == "" )
                s += to_string(i);
            res.push_back(s);
        }
        return res;
    }
};