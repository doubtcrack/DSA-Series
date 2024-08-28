class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        // If out of bounds or water, return true (we don't care about water cells)
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) return true;

        // If the current cell is land in grid2 but water in grid1, it's not a sub-island
        if (grid1[i][j] == 0) return false;

        // Mark the current cell as visited in grid2
        grid2[i][j] = 0;

        // Check all 4 directions
        bool up = dfs(grid1, grid2, i-1, j);
        bool down = dfs(grid1, grid2, i+1, j);
        bool left = dfs(grid1, grid2, i, j-1);
        bool right = dfs(grid1, grid2, i, j+1);

        // If all the parts of this island in grid2 match the corresponding parts in grid1, it's a sub-island
        return up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int count = 0;

        // Traverse all cells in grid2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find an unvisited island part in grid2, start DFS
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;

    }
};