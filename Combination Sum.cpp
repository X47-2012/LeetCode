void combinationSumHelper(const vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int> >& ans) {
    // There is only two conditions: contains candidates[index], not contains candidates[index]
    // in not contains candidates[index] condition, it's only the sub problem, not considering candidates[index]
    // and so on
    
    if (target < 0) {
        return;
    }
    if (target == 0) {
        ans.push_back(path);
        return;   
    }
    
    for (int i = index; i < candidates.size(); i++) {
        if (target >= candidates[i]) {
            path.push_back(candidates[i]); // contains candidates[i]
            combinationSumHelper(candidates, target - candidates[i], i, path, ans); // 
            path.pop_back(); // not contains candidates[i]
        }
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int> > ans;
    if (candidates.size() == 0) {
        return ans;
    }
    sort(candidates.begin(), candidates.end());
    
    combinationSumHelper(candidates, target, 0, path, ans);
    return ans;
}
