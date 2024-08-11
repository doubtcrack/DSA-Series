class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Check if the grid is already disconnected
        if (countIslands(grid) != 1) {
            return 0;
        }
        
        // Try disconnecting by changing one land cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        
        // If one move is not enough, it will take two moves at most.
        return 2;
    }
    
    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int nx = cx + dx;
                int ny = cy + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
};
