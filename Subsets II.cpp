void subsetsHelper(int index, const vector<int> &nums, vector<int> &path, vector<vector<int> > &ans) {
    if (index == nums.size()) {
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        if (index != i && nums[i] == nums[i - 1]) {
            continue;
        }
        path.push_back(nums[i]);
        ans.push_back(path);
        subsetsHelper(i + 1, nums, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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