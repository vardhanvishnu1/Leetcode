class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // Rotate the queue to bring the new element to the front
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!empty()) {int x =  q.front();q.pop();return x;}
        return -1;
    }
    
    int top() {
        if(!empty()) return q.front();
        return -1;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */