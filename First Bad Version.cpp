int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {          
        int mid = left + (right - left) / 2; // avoid overflow
        if (isBadVersion(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (isBadVersion(left)) {
        return left;
    } else {
        return left + 1;
    }
}