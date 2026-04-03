class MinStack {
public:
    // Good call on long long to prevent overflow
    stack<long long> st;
    long long mn;

    MinStack() {
        mn = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mn = val;
            return;
        }
        if (val < mn) {
            // The encoded value is always less than the new mn
            st.push(2LL * val - mn);
            mn = val;
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        if (st.top() < mn) {
            // Restore: prev_min = 2 * current_min - flag_value
            mn = 2 * mn - st.top();
        }
        st.pop();
    }
    
    int top() {
        // If top is the encoded flag, the actual value is current mn
        if (st.top() < mn) {
            return (int)mn; 
        }
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mn;
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