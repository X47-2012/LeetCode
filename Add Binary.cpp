string addBinary(string a, string b) {
        string ans = "";
        if (a.size() == 0) {
            return b;
        }
        if (b.size() == 0) {
            return a;
        }
        
        int i, j;
        int rest = 0;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
            int sum = (a[i] - '0') + (b[j] - '0') + rest;
            rest = sum / 2;
            ans += (char) (sum % 2) + '0';
        }
        if (i >= 0) {
            for (; i >= 0; i--) {
                int sum = (a[i] - '0') + rest;
                rest = sum / 2;
                ans += (char) (sum % 2) + '0';
            }
        }
        if (j >= 0) {
            for (; j >= 0; j--) {
                int sum = (b[j] - '0') + rest;
                rest = sum / 2;
                ans += (char) (sum % 2) + '0';
            }
        }
        if (rest != 0) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int ai = (i < a.size()) ? a[i] - '0' : 0;
            int bi = (i < b.size()) ? b[i] - '0' : 0;
            int num = ai + bi + carry;
            carry = num / 2;
            char val = num % 2 + '0';
            result.insert(result.begin(), val);
        }
        if (carry != 0) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};