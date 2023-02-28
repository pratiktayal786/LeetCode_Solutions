class MinStack {
public:
    stack<int> stk, stkMin;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(stkMin.empty() || val <= getMin()) stkMin.push(val);
    }
    
    void pop() {
        if(stk.top() == getMin()) stkMin.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stkMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */