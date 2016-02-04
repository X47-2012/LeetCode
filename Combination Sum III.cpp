void combinationSum3Helper(int k, int n, int index, vector<int> &path, vector<vector<int> > &ans) {
    if (n < 0) {
        return;
    }
    
    if (path.size() == k) {
        if (n == 0) {
            ans.push_back(path);
            return;
        } else {
            return;
        }
    }
    
    for (int i = index; i <= 9; i++) {
        if (n >= i) {
            path.push_back(i);
            combinationSum3Helper(k, n - i, i + 1, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > ans;
    vector<int> path;
    if (k == 0 || n == 0) {
        return ans;
    }
    combinationSum3Helper(k, n, 1, path, ans);
    return ans;
}