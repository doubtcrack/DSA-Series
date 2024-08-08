class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> result;
    result.push_back({rStart, cStart});
    
    int totalCells = rows * cols;
    int steps = 1;  
    int direction = 0;  // 0: East, 1: South, 2: West, 3: North
    int r = rStart, c = cStart;
    
    // Directions represent the movements: right, down, left, up
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (result.size() < totalCells) {
        for (int i = 0; i < 2; i++) {  // Each pair of directions
            for (int j = 0; j < steps; j++) {
                r += directions[direction][0];
                c += directions[direction][1];
                
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                }
            }
            direction = (direction + 1) % 4;  // Change direction
        }
        steps++;  // Increase steps after a full cycle of directions
    }
    
    return result;
    }
};