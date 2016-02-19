bool isHappy(int n) {
    if (n == 0) {
        return false;
    }
    unordered_set<int> record;
    int sum = n, tmp;
    while (sum != 1) {
        tmp = sum;
        sum = 0;
        while (tmp != 0) {
            int mod = tmp % 10;
            sum += mod * mod;
            tmp /= 10;
        }
        if (record.find(sum) != record.end()) {
            return false;
        } else {
            record.insert(sum);
        }
    }
    return true;
}