void subsetsHelper(int index, const vector<int> &nums, vector<int> &path, vector<vector<int> > &ans) {
    if (index == nums.size()) {
        return;
    }
    // fisrt method
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
    // second method
    /*
    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        ans.push_back(path);
        subsetsHelper(i + 1, nums, path, ans);
        path.pop_back();
    } */
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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        
        subsetsHelper(0, nums, path, res);
        return res;
    }
    
    void subsetsHelper(int index, vector<int> &nums, vector<int> &path, vector<vector<int>> &res) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }
        
        subsetsHelper(index + 1, nums, path, res);
        path.push_back(nums[index]);
        subsetsHelper(index + 1, nums, path, res);
        path.pop_back();
    }
};