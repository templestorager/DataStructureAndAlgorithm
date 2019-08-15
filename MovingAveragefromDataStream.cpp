// Problem Description 
/*
    Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

    Example:

    MovingAverage m = new MovingAverage(3);
    m.next(1) = 1
    m.next(10) = (1 + 10) / 2
    m.next(3) = (1 + 10 + 3) / 3
    m.next(5) = (10 + 3 + 5) / 3
 * 
 * 
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        nums.clear();
        setsz = size;
    }
    
    double next(int val) {
        nums.push_back(val);
        double sum = 0;
        if ( nums.size() <= setsz ) {
            for ( int i = 0; i < nums.size(); i++ ) {
                sum += nums[i];
            } 
            return sum / nums.size();
        } else {
            int i = setsz;
            int j = nums.size() - 1;
            while ( i-- > 0 ) {
                sum += nums[j--];
            }
            return sum / setsz;
        }
    }
    
private:
    vector<int> nums;
    int setsz;
};

// Using a queue to maitain only the requested number of values 
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        qsz = size;
        sum = 0;
    }
    
    double next(int val) {
        if ( nums.size() >= qsz ) {
            sum -= nums.front();
            nums.pop();
        }
        nums.push(val);
        sum += val;
        return sum / nums.size();
    }
    
private:
    queue<int> nums;
    int qsz;
    double sum; 
};