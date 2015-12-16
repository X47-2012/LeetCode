#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
	vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1));
	dp[0][0] = true;

	for (int i = 0; i <= s.size(); i++) {
		for (int j = 1; j <= p.size(); j++) {
            char c = p[j - 1];
			if (c == '*') {
				dp[i][j] = (j > 1 && dp[i][j - 2]) ||
                           (i > 0 && dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
			} else {
                dp[i][j] = (i > 0) && dp[i-1][j-1] && (c == '.' || c == s[i - 1]);
			}
		}
	}

	return dp[s.size()][p.size()];
}

int main() {
	cout << isMatch("aab", "c*a*b");
}
