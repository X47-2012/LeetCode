class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        for (const string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            record[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = record.begin(); it != record.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};