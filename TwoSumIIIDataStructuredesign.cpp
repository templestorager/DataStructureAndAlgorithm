// Problem Description
/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

// Use a vector to store the data and a map to store it's index for convenient check 
// Note this only applies when there is no duplicate nums
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        data.clear();
        m.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number] = data.size();
        data.push_back( number );
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        bool res = false;
        for ( int i = 0; i < data.size(); i++ )
        {
            if ( m.find(value - data[i]) != m.end() && m[value - data[i]] != i )
                res = true;
        }
        return res;
    }
    
private:
    vector<int> data;
    unordered_map<int,int> m;
};

// We can use sorting to facilitating the search, since it doesn't require to know the indices 
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        data.clear();
        Is_Sorted = false;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        data.push_back( number );
        Is_Sorted = false;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if ( !Is_Sorted )
            sort( data.begin(), data.end() );
        #if 0
        int s = 0, e = data.size() - 1;
        while ( s < e )
        {
            if ( data[s] + data[e] == value )
                return true;
            if ( data[s] + data[e] < value )
                s++;
            else
                e--;
        }
        #endif 
        if ( data.size() <= 1 )
            return false;
        vector<int>::const_iterator s = data.begin(), e = --data.end();
        while ( s != e )
        {
            if ( *s + *e == value )
                return true;
            if ( *s + *e < value )
                s++;
            else 
                e--;
        }
        return false;
    }
    
private:
    vector<int> data;
    bool Is_Sorted;
};

// We can also just use one map mapping the value to its frequency 
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for ( unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++ )
        {
            if ( value - it->first == it->first )
            {
                if ( it->second >= 2 ) 
                    return true;
            }
            else if ( m.find(value - it->first) != m.end() )
            {
                return true;
            }

        }
        
        return false;
    }
    
private:
    unordered_map<int,int> m;
};

// Similar to the above solution, we use multiset instead of the map to store implicitly store the frequency.

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m.insert( number );
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for ( auto a : m )
        {
            int targetcnt = a == value - a ?  1 : 0; 
            if ( m.count(value - a)  > targetcnt ) 
                return true;
        }
        return false;
    }
    
private:
    unordered_multiset<int> m;
};