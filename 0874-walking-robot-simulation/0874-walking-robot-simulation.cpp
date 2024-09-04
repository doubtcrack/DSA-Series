class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         // Convert obstacles to a set for quick lookup
        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        // Initial position and direction (facing north)
        int x = 0, y = 0;
        int direction = 0; // 0 = North, 1 = East, 2 = South, 3 = West
        int maxDistanceSquared = 0;

        // Direction vectors for North, East, South, West
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int command : commands) {
            if (command == -2) { // Turn left
                direction = (direction + 3) % 4;
            } else if (command == -1) { // Turn right
                direction = (direction + 1) % 4;
            } else if (command >= 1 && command <= 9) { // Move forward
                for (int i = 0; i < command; ++i) {
                    int newX = x + dx[direction];
                    int newY = y + dy[direction];
                    if (obstacleSet.find(to_string(newX) + "," + to_string(newY)) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        int distSquared = x * x + y * y;
                        maxDistanceSquared = max(maxDistanceSquared, distSquared);
                    }
                }
            }
        }

        return maxDistanceSquared;
    }
};