class MinStack {
private:
    std::stack<int> minStack;
    std::stack<int> stack;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty()) {
            // If stack is empty, just compare val with itself (no change)
            val = val;
        } else {
            // If stack not empty, compare val with top of minStack
            val = std::min(val, minStack.top());
        }
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
