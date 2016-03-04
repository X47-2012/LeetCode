class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix.size();
        if (row_len == 0) {
            return false;
        }
        int col_len = matrix[0].size();
        int row_start = 0, row_end = row_len - 1;
        
        while (row_start <= row_end) {
            int mid = (row_start + row_end) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                row_end = mid - 1;
            } else {
                row_start = mid + 1;
            }
        }
        
        if (row_end < 0) {
            return false;
        }
        
        int col_start = 0, col_end = col_len - 1;
        while (col_start <= col_end) {
            int mid = (col_start + col_end) / 2;
            if (matrix[row_end][mid] == target) {
                return true;
            } else if (matrix[row_end][mid] > target) {
                col_end = mid - 1;
            } else {
                col_start = mid + 1;
            }
        }
        
        return false;
    }
};