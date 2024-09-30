// 30.09.24 POTD
class CustomStack {
public:
    vector<int> stk;
    int sz;
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(stk.size() < sz)
            stk.push_back(x);
    }
    
    int pop() {
        if(stk.size()){
            int p = stk.back();
            stk.pop_back();
            return p;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<stk.size(); i++){
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */