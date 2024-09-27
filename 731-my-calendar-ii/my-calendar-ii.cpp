// 27.09.24 potd
class MyCalendarTwo {
public:
    map<int,int> events;

    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int activeBookings = 0;

        // Sweep through the events in chronological order
        for(auto &event: events){
            activeBookings += event.second;

            if(activeBookings >= 3){
                // Revert the changes as the booking is not valid
                events[start]--;
                events[end]++;

                // Delete from map, as they're of no need
                if(events[start] == 0)  
                    events.erase(start);
                if(events[end] == 0)
                    events.erase(end);

                return false;
            }

            if(event.first > end){
                break;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */