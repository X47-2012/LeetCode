#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if ((dp[j] == 1) && (wordDict.find(s.substr(j, i - j)) != wordDict.end())) {
                flag = true;
                break;
            }
        }
        if (flag == true)
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    return dp[s.size()] == 1;
}

int main() {
    set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");

    cout << wordBreak("leetcode", wordDict);
}
