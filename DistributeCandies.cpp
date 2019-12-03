// Problem Description 
/*
    Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
    Example 1:
    Input: candies = [1,1,2,2,3,3]
    Output: 3
    Explanation:
    There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
    Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
    The sister has three different kinds of candies. 
    Example 2:
    Input: candies = [1,1,2,3]
    Output: 2
    Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
    The sister has two different kinds of candies, the brother has only one kind of candies. 
    Note:

    The length of the given array is in range [2, 10,000], and will be even.
    The number in given array is in range [-100,000, 100,000].
 * 
 */

// The key is to convert this question to calculate the types of candies 
// Both brother and sister are to have n/2 candies. Therefore, if there are more than n/2 types, then 
// the sister can choose each one from each type. Otherwise, she can choose one from each type and the remaing 
// (n/2 - types) from any types, which woundn't increase her chosen types. 
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candytype;
        for ( int candy : candies ) {
            candytype.insert(candy);
        }
        
        return min(candytype.size(), candies.size() / 2 );
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(candies.begin(),candies.end()).size(),candies.size()/2);
    }
};