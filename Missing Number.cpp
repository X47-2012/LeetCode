class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += nums[i];
        }
        
        return (1 + n) * n / 2 - x;
    }
};