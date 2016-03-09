class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) {
            return 0;
        }
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (citations[mid] == len - mid) {
                return citations[mid];
            } else if (citations[mid] < len - mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= len) {
            return 0;
        }
        return min(len - left, citations[left]);
    }
};