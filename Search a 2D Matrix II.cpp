class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix.size();
        if (row_len == 0) {
            return false;
        }
        int col_len = matrix[0].size();
        
        int row = 0, col = col_len - 1;
        
        while (row < row_len && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                int row_start = row + 1, row_end = row_len - 1;
                while (row_start <= row_end) {
                    int mid = (row_start + row_end) >> 1;
                    if (matrix[mid][col] == target) {
                        return true;
                    } else if (matrix[mid][col] < target) {
                        row_start = mid + 1;
                    } else {
                        row_end = mid - 1;
                    }
                }
                if (row_end == col_len - 1) {
                    return false;
                } else {
                    row = row_end + 1;
                }
            } else {
                int col_start = 0, col_end = col - 1;
                while (col_start <= col_end) {
                    int mid = (col_start + col_end) >> 1;
                    if (matrix[row][mid] == target) {
                        return true;
                    } else if (matrix[row][mid] < target) {
                        col_start = mid + 1;
                    } else {
                        col_end = mid - 1;
                    }
                }
                if (col_end < 0) {
                    return false;
                } else {
                    col = col_end;
                }
            }
        }
        
        return false;
    }
};


/*
    just delete a row or a column
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)  return false;
        int n=matrix[0].size();
        /*** start from the right-up-position ***/
        int i=0, j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]==target)  return true;
            /*** the element-of-column-j >= matrix[i][j] > target ***/
            else if(matrix[i][j]>target)  j--;
            /*** the element-of-row-i <= matrix[i][j] < target ***/
            else   i++;
        }
        return false;
    }
};