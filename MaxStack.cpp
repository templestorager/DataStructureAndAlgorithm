// Problem Description 
/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/

// This straightforward solution uses two stack to maintain the stacked values and their corresponding 
// max value, respectively. 

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
    
    }
    
    void push(int x) {
        int newmax = maxs.empty() ? x : max(maxs.top(),x);
        s.push(x);
        maxs.push(newmax);
    }
    
    int pop() {
        maxs.pop();
        int res = s.top();
        s.pop();
        return res;
    }
    
    int top() {
        return s.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    // when pop max, we store all elements less than the poped max in the regular stack 
    // and then store it back. 
    // note that while we pop the elements from the regular stack, it also pops the corresponding max from the maxstack 
    // and while we push then in the regular stack, it also pushes in the max stack 
    int popMax() {
        int curmax = peekMax();
        stack<int> tmps;
        while( top() != curmax )
        {
            tmps.push(pop());
        }
        pop();
        while (!tmps.empty())
        {
            push(tmps.top());
            tmps.pop();
        }
        return curmax;
    }
    
private:
    stack<int> s;
    stack<int> maxs;
};