class Solution {
public:
    bool isAnagram(string s, string t) {
        int record1[26];
        int record2[26];
        memset(record1, 0, 26 * sizeof(int));
        memset(record2, 0, 26 * sizeof(int));

        for (int i = 0; i < s.size(); i++) {
            record1[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++) {
            record2[t[i] - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (record1[i] != record2[i]) {
                return false;
            }
        }
        return true;
    }
};
