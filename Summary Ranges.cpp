class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if (nums.size() == 0) {
            return vec;
        }

        string str = "";
        for (int i = 0; i < nums.size(); i++) {
            stringstream ss;
            if ((i == nums.size() - 1) || (nums[i + 1] != nums[i] + 1)) {
                if ((i != 0) && (nums[i] == nums[i - 1] + 1)) {
                    str += "->";
                }
                ss << nums[i];
                str += ss.str();
                vec.push_back(str);
                str = "";
            } else if (str.size() == 0) {
                ss << nums[i];
                str += ss.str();
            }
        }
        return vec;
    }
};
