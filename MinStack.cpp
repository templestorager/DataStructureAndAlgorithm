// Proble Description 
/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant 
 * time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack() 
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2. 
 */


// This solution uses two stacks. 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if ( min_val.empty() || x <= min_val.top() )
            min_val.push(x);
    }
    
    void pop() {
        if ( data.top() == min_val.top() )
            min_val.pop();
        data.pop();       
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_val.top();
    }
private:
    stack<int> data, min_val;
};

// In this solution the min_val share the same stack as the data series
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        if ( x <= min_val ) {
            data.push(min_val);
            min_val = x;
        }
        data.push(x);
    }
    
    void pop() {
        int top = data.top();
        data.pop();
        if ( top == min_val ) {
            min_val = data.top();
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_val;
    }
private:
    stack<int> data;
    int min_val;
};