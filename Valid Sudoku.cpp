#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
    int row_flag[10];
    int col_flag[10];
    int mat_flag[10];

    for (int i = 0; i < 10; i++) {
        memset(row_flag, 0, 10 * sizeof(int));
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == '.') continue;

            if (row_flag[board[i][j] - '0'] == 1)
                return false;
            else
                row_flag[board[i][j] - '0'] = 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        memset(col_flag, 0, 10 * sizeof(int));
        for (int j = 0; j < 10; j++) {
            if (board[j][i] == '.') continue;

            if (col_flag[board[j][i] - '0'] == 1)
                return false;
            else
                col_flag[board[j][i] - '0'] = 1;
        }
    }

    for (int i = 0; i <= 6; i += 3) {
        for (int j = 0; j <= 6; j += 3) {
            memset(mat_flag, 0, 10 * sizeof(int));
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (board[i + m][j + n] == '.') continue;

                    if (mat_flag[board[i + m][j + n] - '0'] == 1)
                        return false;
                    else
                        mat_flag[board[i + m][j + n] - '0'] = 1;
                }
            }
        }
    }

    return true;
}

int main() {

}
