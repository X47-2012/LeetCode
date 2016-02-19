#include <vector>
#include <string>
#include <iostream>
using namespace std;

void getPermutationHelper(vector<int> &cand, int k, int index, vector<string> &vec, string &ans) {
    if (ans.size() == cand.size()) {
        vec.push_back(ans);
        return;
    }

    for (int i = index; i < cand.size(); i++) {
        ans.push_back((char) (cand[i] + '0'));
        swap(cand[index], cand[i]);
        getPermutationHelper(cand, k, index + 1, vec, ans);
        if (vec.size() == k) {
            return;
        }
        swap(cand[index], cand[i]);
        ans.pop_back();
    }
}

string getPermutation(int n, int k) {
    string ans;
    if (n == 0 || k == 0) {
        return ans;
    }

    vector<int> cand;
    for (int i = 1; i <= n; i++) {
        cand.push_back(i);
    }
    vector<string> vec;

    getPermutationHelper(cand, k, 0, vec, ans);
    return vec.back();
}

int main() {
    string ans = getPermutation(3, 3);
    cout << ans << endl;
}
