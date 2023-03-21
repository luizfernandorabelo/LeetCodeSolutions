class MinStack {
private:
    vector<int> elements;
    vector<int> minimums;
public:
    MinStack() {

    }
    
    void push(int val) {
        elements.push_back(val); 
        if (minimums.empty() || minimums.back() >= val)
            minimums.push_back(val);
    }
    
    void pop() {
        if (elements.back() == minimums.back())
            minimums.pop_back();
        elements.pop_back();
    }
    
    int top() {
        return elements.back();
    }
    
    int getMin() {
        return minimums.back();
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
