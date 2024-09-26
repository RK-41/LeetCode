class MyCalendar {
    // 26.09.24 POTD
    map<int,int> intervals;    
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = intervals.lower_bound(start);

        if(next != intervals.end() && next->first < end){
            return false;   // overlap with next interval
        }

        if(next != intervals.begin() && prev(next)->second > start){
            return false;   // overlap with previous interval
        }

        intervals[start] = end; // no overlap

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */