class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int base = 5;
        while (true) {
            if (n / base < 1) {
                break;
            }
            for (int i = n; i >= 1 && i / base > 0; i--) {
                if (i % base == 0) {
                    ans++;
                    i = i - base + 1;
                }
            }
            base *= 5;
        }
        return ans;
    }
};