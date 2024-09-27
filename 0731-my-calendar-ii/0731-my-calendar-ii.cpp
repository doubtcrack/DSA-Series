class MyCalendarTwo {
private:
vector<pair<int, int>> singleBookings;
vector<pair<int, int>> doubleBookings;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        for (const auto& event : doubleBookings) {
            int overlapStart = max(start, event.first);
            int overlapEnd = min(end, event.second);
            if (overlapStart < overlapEnd) {
                return false; 
            }
        }

        for (const auto& event : singleBookings) {
            int overlapStart = max(start, event.first);
            int overlapEnd = min(end, event.second);
            if (overlapStart < overlapEnd) {
                doubleBookings.push_back({overlapStart, overlapEnd});
            }
        }

        singleBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */