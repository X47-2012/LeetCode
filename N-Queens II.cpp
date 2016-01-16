bool isValid(int row, int col, const vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == col || row - i == abs(path[i] - col)) {
            return false;
        }
    }
    return true;
}

void totalNQueensHelper(int row, const int n, vector<int> &path, int &ans) {
    if (row == n) {
       ans += 1;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!isValid(row, col, path)) {
            continue;
        }
        path.push_back(col);
        totalNQueensHelper(row + 1, n, path, ans);
        path.pop_back();
    }
}

int totalNQueens(int n) {
    vector<int> path;
    int ans = 0;
    if (n == 0) {
        return ans;
    }
    totalNQueensHelper(0, n, path, ans);
    return ans;
}