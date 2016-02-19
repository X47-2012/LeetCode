vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    if (n == 0) {
        return digits;
    }
    digits[n - 1] += 1;
    int add = 0;
    for (int i = n - 1; i >= 0; i--) {
        int tmp = digits[i] + add;
        digits[i] = tmp % 10;
        add = tmp / 10;
    }
    if (add != 0) {
        digits.insert(digits.begin(), add);
    }
    return digits;
}