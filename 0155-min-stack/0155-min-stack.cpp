class MinStack {
public:
    
    stack<pair<int,int>> stk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int min;
        if(stk.empty()) min = val;
        else{
            min = std::min(stk.top().second, val);
        }
        stk.push({val, min});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
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