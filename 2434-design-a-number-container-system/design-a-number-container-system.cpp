class NumberContainers {
public:
    // 08.02.25 POTd
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numIdx;    // Indexes at which a particular num is present
    unordered_map<int, int> idxNum; // {idx: num}
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(idxNum.count(index)){
            int prevNum = idxNum[index];
            if(prevNum == number)   return;
            numIdx[prevNum].push(INT_MAX);  // Lazy detection
        }

        idxNum[index] = number;
        numIdx[number].push(index);
    }
    
    int find(int number) {
        while(!numIdx[number].empty() && idxNum[numIdx[number].top()] != number){
            numIdx[number].pop();
        }        

        return numIdx[number].empty() ? -1 : numIdx[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */