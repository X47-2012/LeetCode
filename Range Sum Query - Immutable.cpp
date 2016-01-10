class NumArray {
public:
    vector<int> record;
    NumArray(vector<int> &nums) {
        record.push_back(0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            record.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return record[j + 1] - record[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);