// Problem Description
/*
    Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

    Example 1:

    Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
    Output: [1,5]
    Explanation: Only 1 and 5 appeared in the three arrays.
    
    Constraints:
    1 <= arr1.length, arr2.length, arr3.length <= 1000
    1 <= arr1[i], arr2[i], arr3[i] <= 2000
 */

// Key idea to obtain the max of the three and advance the other two until a no-less value is encountered 
// O(n), O(1)
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while ( 1 ) {
            if ( arr1[i] == arr2[j] && arr2[j] == arr3[k] ) {
                res.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }

           else { 
                int max_val = max( arr1[i], max(arr2[j],arr3[k] ) ) ;
                while ( i < arr1.size() && arr1[i] < max_val ) 
                    i++;
                while ( j < arr2.size() && arr2[j] < max_val )
                    j++;
                while ( k < arr3.size() && arr3[k] < max_val ) 
                    k++;
           }
            if ( i == arr1.size() || j == arr2.size() || k == arr3.size() ) 
                break;
        }
        
        return res;
    }
};