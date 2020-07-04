// Problem Description 
/*
Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

// This soluiton uses a customized cmp to sort the elements and then take the first k after the sort 
// This nice (as well as bad) feature of this solution is that it doesn't rely on (or leverage) the array being sorted
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        sort( arr.begin(), arr.end(), [&x](int a, int b) { if ( abs(a-x) < abs(b-x) ) return true; else if ( abs(a-x) == abs(b-x) ) { if ( a < b ) return true; else return false;} else return false;} );
        for ( int i = 0; i < k; i++ )
            res.push_back( arr[i] );
        sort( res.begin(), res.end() );
        return res;
    }
};

// Actually, it is equal to remove n-k elements from the two ends 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size() - 1;
        vector<int> res;
        while ( j-i+1 > k )
        {
            if ( abs(arr[i] - x) > abs(arr[j]-x) ) 
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        for ( int k = i; k <= j; k++ )
            res.push_back( arr[k] );
        return res;
    }
};

// This is essentailly a binary search with the bunch of k elments being perceived one unit. 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size() - k;
        while ( i < j )
        {
            int mid = i + (j-i)/2;
            if ( x-arr[mid] > arr[mid+k] - x ) 
                i = mid + 1;
            else 
                j = mid;
        }
        return vector<int>(arr.begin()+i,arr.begin()+j+k);
    }
};


// This solution finds its position in the array first, then expand and shrink 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), pos, left, right;
        if ( arr[0] >= x ) 
            return vector<int>(arr.begin(),arr.begin()+k);
        if ( arr[n-1] <= x )
            return vector<int>(arr.end()-k,arr.end());
        pos = FindBinaryPosition( arr, x );
        left = max(pos - k,0);
        right = min(pos + k,n-1);
        while ( right - left + 1 > k )
        {
            if ( abs(arr[left]-x) > abs(arr[right]-x) )
                left++;
            else 
                right--;
        }
        
        return vector<int> (arr.begin()+left, arr.begin()+right+1);
    }
    
    int FindBinaryPosition( vector<int> &arr, int val )
    {
        int i = 0, j = arr.size()-1;
        while ( i < j )
        {
            int mid = i + (j-i)/2;
            if ( arr[mid] < val ) 
                i = mid + 1;
            else if ( arr[mid] == val )
                return mid;
            else 
                j = mid;
        }
        
        return i;
    }
};