void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) {
        return;
    }
    for (int i = m - 1; i >= 0; i--) {
        nums1[i + n] = nums1[i];
    }
    int idx = 0, idx1 = n, idx2 = 0;
    while (idx1 < m + n && idx2 < n) {
        if (nums1[idx1] <= nums2[idx2]) {
            nums1[idx++] = nums1[idx1++];
        } else {
            nums1[idx++] = nums2[idx2++];
        }
    }
    if (idx1 == m + n) {
        while (idx2 < n) {
            nums1[idx++] = nums2[idx2++];
        }
    }
}