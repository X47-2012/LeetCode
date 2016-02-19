int hammingWeight(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    int ans = 1;
    while (n != 1) {
        ans += (n % 2);
        n = n / 2;
    }
    return ans;
}