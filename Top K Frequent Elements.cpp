bool cmp(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return p1.second > p2.second; 
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.count(nums[i]) > 0) {
                record[nums[i]] += 1;
            } else {
                record[nums[i]] = 1;
            }
        }
        
        vector<std::pair<int, int>> sort_record;
        for (auto it = record.begin(); it != record.end(); it++) {
            sort_record.push_back(make_pair(it->first, it->second));
        }
        
        sort(sort_record.begin(), sort_record.end(), cmp);
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(sort_record[i].first);
        }
        
        return result;
    }
};