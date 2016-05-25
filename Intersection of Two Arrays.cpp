class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        
        if (set1.size() <= set2.size()) {
            for (auto p = set1.begin(); p != set1.end(); p++) {
                if (set2.count(*p) > 0) {
                    result.push_back(*p);
                }
            }
        } else {
            for (auto p = set2.begin(); p != set2.end(); p++) {
                if (set1.count(*p) > 0) {
                    result.push_back(*p);
                }
            }
        }
        
        return result;
    }
};