void permuteUniqueHelper(int index, vector<int> &nums, vector<vector<int> > &ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    
    unordered_set<int> used;
    for (int i = index; i < nums.size(); i++) {
        if (used.count(nums[i]) != 0) {
            continue;
        }
        swap(nums[index], nums[i]);
        permuteUniqueHelper(index + 1, nums, ans);
        swap(nums[index], nums[i]);
        used.insert(nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > ans;
    if (nums.size() == 0) {
        return ans;
    }
    permuteUniqueHelper(0, nums, ans);
    return ans;
}