class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, 0));
        int count = 1;
        int row = 0, col = 0;
        while (count <= n * n) {
            for (; col < n && output[row][col] == 0; col++) {
                output[row][col] = count;
                count++;
            }
            col--;
            row++;
            for (; row < n && output[row][col] == 0; row++) {
                output[row][col] = count;
                count++;
            }
            row--;
            col--;
            for (; col >= 0 && output[row][col] == 0; col--) {
                output[row][col] = count;
                count++;
            }
            col++;
            row--;
            for (; row >= 0 && output[row][col] == 0; row--) {
                output[row][col] = count;
                count++;
            }
            row++;
            col++;
        }
        return output;
    }
};