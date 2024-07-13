class Solution {
public:
struct Robot {
    int position;
    int health;
    char direction;
};
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], healths[i], directions[i]};
        }

        // Sort robots by position
        sort(robots.begin(), robots.end(), [](const Robot &a, const Robot &b) {
            return a.position < b.position;
        });

        stack<Robot> st;
        for (auto &robot : robots) {
            if (robot.direction == 'R') {
                st.push(robot);
            } else { 
                while (!st.empty() && st.top().direction == 'R') {
                    Robot top = st.top();
                    if (top.health < robot.health) {
                        st.pop();
                        robot.health -= 1;
                    } else if (top.health == robot.health) {
                        st.pop();
                        robot.health = -1; // robot is also destroyed
                        break;
                    } else {
                        st.top().health -= 1;
                        robot.health = -1;
                        break;
                    }
                }
                if (robot.health > 0) {
                    st.push(robot);
                }
            }
        }
    
        // Collect survivors
        vector<int> result;
        while (!st.empty()) {
            Robot robot = st.top();
            st.pop();
            result.push_back(robot.health);
        }
        return result;
    }
};