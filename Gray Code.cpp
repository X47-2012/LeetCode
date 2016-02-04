#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;

bool valid(string str1, string str2) {
    int sum = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            sum++;
        }
    }
    return (sum == 1);
}

int transfer(string code) {
    int sum = 0;
    int base = 1;
    for (int i = code.size() - 1; i >= 0; i--) {
        sum += (code[i] - '0') * base;
        base *= 2;
    }
    return sum;
}

void grayCodeHelper(int n, int total, string code, unordered_set<string> &record, vector<int> &ans) {
    if (ans.size() == total) {
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        string tmp = string(code);
        tmp[i] = (char) (1 - (tmp[i] - '0') + '0');
        if ((record.find(tmp) == record.end()) && valid(code, tmp)) {
            ans.push_back(transfer(tmp));
            record.insert(tmp);
            grayCodeHelper(n, total, tmp, record, ans);
        }
    }
}

vector<int> grayCode(int n) {
    vector<int> ans;
    int total = pow(2, n);

    unordered_set<string> record;
    string code(n, '0');

    ans.push_back(0);
    record.insert(code);

    if (n == 0) {
        return ans;
    }
    grayCodeHelper(n, total, code, record, ans);
    return ans;
}

int main() {
    vector<int> ans = grayCode(3);

    for (int i = 0; i < 8; i++) {
        cout << ans[i] << " ";
    }
}
