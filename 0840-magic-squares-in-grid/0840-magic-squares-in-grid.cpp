class Solution {
public:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
    // Check if all values are distinct and between 1 to 9
    set<int> uniqueNumbers;
    for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
            // !uniqueNumbers.insert(grid[i][j]).second) here it is checking if the value is inserted in the set or not. The insert function returns a pair containing iterator and bool so the .second used above is providing the boolean value 
            if (grid[i][j] < 1 || grid[i][j] > 9 || !uniqueNumbers.insert(grid[i][j]).second) {
                return false;
            }
        }
    }

    // Calculate the sum of the first row
    int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
    
    // Check the sums of the remaining rows
    for (int i = 1; i < 3; ++i) {
        if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum) {
            return false;
        }
    }
    
    // Check the sums of the columns
    for (int j = 0; j < 3; ++j) {
        if (grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j] != sum) {
            return false;
        }
    }
    
    // Check the sums of the diagonals
    if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) {
        return false;
    }
    if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) {
        return false;
    }
    
    return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    
    for (int i = 0; i <= rows - 3; ++i) {
        for (int j = 0; j <= cols - 3; ++j) {
            if (isMagicSquare(grid, i, j)) {
                count++;
            }
        }
    }

    return count;
}
};