int titleToNumber(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int ans = 0;
    int inx = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += inx * (s[i] - 'A' + 1);
        inx *= 26;
    }
    return ans;
}