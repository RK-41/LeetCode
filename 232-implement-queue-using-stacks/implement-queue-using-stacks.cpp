// 29.01.24 (POTD)

class MyQueue {
public:
    stack<int> st;
    stack<int> t;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(st.size()){
            t.push(st.top());
            st.pop();
        }
        t.push(x);

        while(t.size()){
            st.push(t.top());
            t.pop();
        }
    }
    
    int pop() {
        if(st.size()){
            int d=st.top();
            st.pop();
            return d;
        }

        return -1;
    }
    
    int peek() {
        return st.size()?st.top():-1;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */