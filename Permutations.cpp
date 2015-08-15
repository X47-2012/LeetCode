#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void backtracking(vector<int>& nums, vector<vector<int> > &ans, int k, int n) {
    if (k == n) {
        ans.push_back(nums);
        return;
    }

    for (int i = k; i < n; i++) {
        swap(nums[k], nums[i]);
        backtracking(nums, ans, k + 1, n);
        swap(nums[k], nums[i]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ans;
    backtracking(nums, ans, 0, nums.size());
    return ans;
}

int main() {
    vector<int> nums;
    for (int i = 1; i <= 3; i++)
        nums.push_back(i);

    vector<vector<int> > ans = permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] < " ";
        }
        cout << endl;
    }
}
