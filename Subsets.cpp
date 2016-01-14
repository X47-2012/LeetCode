void subsetsHelper(int index, const vector<int> &nums, vector<int> &path, vector<vector<int> > &ans) {
    if (index == nums.size()) {
        return;
    }
    
    for (int i = 0; i <= 1; i++) {
        if (i == 0) {
            subsetsHelper(index + 1, nums, path, ans);
        } else {
            path.push_back(nums[index]);
            ans.push_back(path);
            subsetsHelper(index + 1, nums, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    ans.push_back(vector<int>());
    vector<int> path;
    sort(nums.begin(), nums.end());
    if (nums.size() == 0) {
        return ans;
    }
    subsetsHelper(0, nums, path, ans);
    return ans;
}