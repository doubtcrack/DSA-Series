class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;

        for (const auto& interval : intervals) {
            events.push_back({interval[0], 1});    
            events.push_back({interval[1] + 1, -1});  
        }

        sort(events.begin(), events.end());
        int activeIntervals = 0;
        int maxGroups = 0;

        for (const auto& event : events) {
            activeIntervals += event.second;
            maxGroups = max(maxGroups, activeIntervals);
        }

        return maxGroups;
    }
};