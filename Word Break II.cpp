#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool isWordBreak(string s, unordered_set<string>& wordDict) {
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

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<vector<string> > dp(s.size() + 1);
    if (!isWordBreak(s, wordDict))
        return dp[0];

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                if (dp[j].size() == 0) {
                    if (j == 0)
                        dp[i].push_back(s.substr(j, i - j));
                } else {
                    for (int k = 0; k < dp[j].size(); k++) {
                        dp[i].push_back(dp[j][k] + " " + s.substr(j, i - j));
                    }
                }
            }
        }
    }
    return dp[s.size()];
}

int main() {
    string strs[] = {"aaaa", "aaa"};
    set<string> wordDict;
    for (int i = 0; i < 2; i++)
        wordDict.insert(strs[i]);

    vector<string> ans = wordBreak("aaaaaaa", wordDict);
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
