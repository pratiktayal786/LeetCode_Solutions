class MinStack {
public:
    stack<int> stk, stkMin;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        pushInMinStack(stkMin, val);
    }
    
    void pop() {
        int val = stk.top();
        stk.pop();
        popFromMinStack(stkMin, val);
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stkMin.top();
    }
    
    void pushInMinStack(stack<int> &stk, int val){
        
        if(stk.empty()){
            stk.push(val);
            return;
        }
        int data = stk.top();
        if(data > val){
            stk.push(val);
            return;
        }
        else{
            stk.pop();
            pushInMinStack(stk, val);
            stk.push(data);
            return;
        }
    }
    
    void popFromMinStack(stack<int> &stk, int val){
        
        if(stk.empty()) return;
        
        int data = stk.top();
        if(data == val){
            stk.pop();
            return;
        }
        else{
            stk.pop();
            popFromMinStack(stk, val);
            stk.push(data);
            return;
        }
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