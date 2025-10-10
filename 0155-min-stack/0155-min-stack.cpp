class MinStack {
public:
stack<long long>st;
 long long mn ;
    MinStack() {
        mn = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            mn =val;
            return;
        }
        if(val<mn){
            st.push(2LL*val-mn);
            mn = val;
            return;
        }
        st.push(val);
        return;
    }
    
    void pop() {
        if(st.top()<mn){
            mn = 2*mn-st.top();
        }
        st.pop();
    }
    
    int top() {
       if(st.top()<mn){return mn;}
       return  st.top();
    }
    
    int getMin() {
        return mn;
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