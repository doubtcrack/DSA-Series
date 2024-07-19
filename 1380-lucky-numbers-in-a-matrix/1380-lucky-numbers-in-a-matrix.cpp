class Solution {
public:

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> minInRows;
    vector<int> result;
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: Find the minimum element in each row
    for (int i = 0; i < rows; ++i) {
        int minVal = *min_element(matrix[i].begin(), matrix[i].end());
        minInRows.push_back(minVal);
    }

    // Step 2: Check if the minimum elements are the maximum in their columns
    for (int i = 0; i < rows; ++i) {
        int minVal = minInRows[i];
        int colIndex = find(matrix[i].begin(), matrix[i].end(), minVal) - matrix[i].begin();
        bool isMaxInCol = true;

        for (int j = 0; j < rows; ++j) {
            if (matrix[j][colIndex] > minVal) {
                isMaxInCol = false;
                break;
            }
        }

        if (isMaxInCol) {
            result.push_back(minVal);
        }
    }

    return result;
    }
};