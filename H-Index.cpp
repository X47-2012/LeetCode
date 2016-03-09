class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 1; i <= citations.size(); i++) {
            int tmp = min(i, citations[i - 1]);
            if (tmp > result) {
                result = tmp;
            }
        }
        return result;
    }
};