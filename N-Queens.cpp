bool isValid(int row, int col, const vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == col || row - i == abs(path[i] - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueensHelper(int row, const int n, vector<int> &path,  vector<vector<string> > &ans) {
    if (row == n) {
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            string str(n, '.');
            str[path[i]] = 'Q';
            tmp.push_back(str);
        }
        ans.push_back(tmp);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!isValid(row, col, path)) {
            continue;
        }
        path.push_back(col);
        solveNQueensHelper(row + 1, n, path, ans);
        path.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > ans;
    vector<int> path;
    if (n == 0) {
        return ans;
    }
    solveNQueensHelper(0, n, path, ans);
    return ans;
}