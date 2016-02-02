void combinationSumHelper(const vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int> >& ans) {
    
    if (target < 0) {
        return;
    }
    if (target == 0) {
        ans.push_back(path);
        return;   
    }
    
    for (int i = index; i < candidates.size(); i++) {
        if (i != index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        path.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], i + 1, path, ans);
        path.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int> > ans;
    if (candidates.size() == 0) {
        return ans;
    }
    sort(candidates.begin(), candidates.end());
    
    combinationSumHelper(candidates, target, 0, path, ans);
    return ans;
}
