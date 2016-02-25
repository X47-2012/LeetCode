class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n != 0) {
            n -= 1;
            int digit = n % 26;
            ans += (char) (digit + 'A');
            n = n / 26;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};