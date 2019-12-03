// Problem Description
/*
    Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

    You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

    Example 1:
    Input:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
    Output: ["Shogun"]
    Explanation: The only restaurant they both like is "Shogun".
    Example 2:
    Input:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["KFC", "Shogun", "Burger King"]
    Output: ["Shogun"]
    Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
    Note:
    The length of both lists will be in the range of [1, 1000].
    The length of strings in both lists will be in the range of [1, 30].
    The index is starting from 0 to the list length minus 1.
    No duplicates in both lists.
 * 
 */


// We check each each pair of the same string between these two lists and remember their least index sum 
// if a new least sum is encountered, we update the result with the new result
// O(L1+L2), O(L1)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m1;
        vector<string> res;
        int minidxsum = INT_MAX;
        for ( int i = 0; i < list1.size(); i++ ) 
            m1[list1[i]] = i;
        for ( int j = 0; j < list2.size(); j++ ) 
        {
            if ( m1.count(list2[j]) ) {
                if ( m1[list2[j]] + j < minidxsum ) {
                    res.clear();
                    res.push_back(list2[j]);
                    minidxsum = m1[list2[j]] + j;
                }
                else if ( m1[list2[j]] + j == minidxsum ) 
                {
                    res.push_back(list2[j]);
                }
            }
        }
        
        return res;
    }
};


// we checkt the possible sum values from the least to the most
// and once we find pairs for the currently examined sum, then we terminate
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int maxidxsum = list1.size() + list2.size() - 2;
        vector<string> res;
        bool found = false;
        for ( int i = 0; i <= maxidxsum && !found; i++ ) {
            res.clear();
            for ( int j = 0;j <= i; j++ ) {
                if ( j < list1.size() && i-j < list2.size() && list1[j] == list2[i-j] ) {
                    res.push_back(list1[j]);
                    found = true;
                }
            }
        }
        
        return res;
    }
};