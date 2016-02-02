void combineHelper(int x, int k, int n, vector<int> &path, vector<vector<int> > &ans) {
    if (x > n) {
        return;
    }
    
    path.push_back(x);
    
    if (path.size() == k) {
        ans.push_back(path);
        path.pop_back();
        return;
    }
    
    for (int i = x + 1; i <= n; i++) {
        combineHelper(i, k, n, path, ans);
    }
    
    path.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> path;
    if (n == 0 || k == 0) {
        return ans;
    }
    for (int i = 1; i <= n; i++) {
        combineHelper(i, k, n, path, ans);
    }
    
    return ans;
}