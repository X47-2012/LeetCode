class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);
        int start = 0, max_len = 1;
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
            for (int j = 0; j < i; j++) {
                f[j][i] = ((s[i] == s[j]) && (i - j < 2 || f[j + 1][i - 1] == true));
                if (f[j][i] && (i - j + 1) > max_len) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

// todo: Manacher算法