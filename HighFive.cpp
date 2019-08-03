// Problem Description 
/*
    Given a list of scores of different students, return the average score of each student's top 
    five scores in the order of each student's id.
    Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

    
    Example 1:

    Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
    Output: [[1,87],[2,88]]
    Explanation: 
    The average of the student with id = 1 is 87.
    The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
    

    Note:

    1 <= items.length <= 1000
    items[i].length == 2
    The IDs of the students is between 1 to 1000
    The score of the students is between 1 to 100
    For each student, there are at least 5 scores
 * 
 */

// This solution uses a priority for each student 
// O(n) O(n) 
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int,vector<int>,greater<int>> > idscoremap;
        vector<vector<int> > res;
        for ( int i = 0; i < items.size(); i++ ) 
        {
            idscoremap[items[i][0]].push(items[i][1]);
            if ( idscoremap[items[i][0]].size() > 5 ) 
                idscoremap[items[i][0]].pop();
        }
        
        for ( auto m : idscoremap ) 
        {
            vector<int> highfive; 
            int sum = 0;
            highfive.push_back(m.first);
            while ( m.second.size() ) 
            {
                sum += m.second.top();
                m.second.pop();
            }
            highfive.push_back(sum/5);
            res.push_back(highfive);
        }
        return res;
    }
};

// this method sorts the records first based on id (increasing) and score(descreasing) 
// then check the first five scores of each student's records 
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int> > res;
        int n = items.size();
        if ( n == 0 )
            return res;
        sort(items.begin(),items.end(),comparefun);
        vector<vector<int>>::iterator it = items.begin();
        int firstid = (*it)[0];
        int lastid = firstid;
        int firstsum = (*it)[1];
        for ( int i = 0; i < 4; i++ ) {
            it++;
            firstsum += (*it)[1];
        }
        res.push_back(vector<int>({firstid,firstsum/5}));
        while ( it != items.end() ) {
            int currentid = (*it)[0];
            if  ( currentid == lastid ) {
                it++;
                continue;
            }
            lastid = currentid;
            int sum = (*it)[1];
            int scores = 4;
            while ( scores-- ) {
                it++;
                if ( (*it)[0] != currentid ) {
                    assert(0); // there are less than five scores for the student 
                }
                sum += (*it)[1];
            }
            res.push_back(vector<int>({currentid,sum/5}));
            it++;
        }
        
        return res;
    }
    
    static bool comparefun( const vector<int> a, const vector<int> b) {
        if ( a[0] == b[0] ) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }
};