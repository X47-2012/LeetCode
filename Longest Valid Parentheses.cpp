#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    int len = s.size();
    if (len <= 1) return 0;
    
    int * dp = new int[len + 1];
    memset(dp, 0, (len + 1) * sizeof(int));
    stack<pair<char, int> > sta;
    
    for (int i = 1; i <= len; i++) {
        pair<char, int> p (s[i - 1], i);
        // cout << p.first << " " << p.second << endl;
        
        if (sta.empty() || s[i - 1] == '(') {
           sta.push(p);
           dp[i] = 1;
        }
        else {
             pair<char, int> p_tmp = sta.top();
             if (p_tmp.first == ')') {
                sta.push(p);
                dp[i] = 1;            
             }
             else {
                  sta.pop();
                  if (dp[p_tmp.second - 1] != 1) {
                     dp[i] = dp[p_tmp.second - 1] + (i - p_tmp.second + 1);
                  } else {
                    dp[i] = (i - p_tmp.second + 1);
                  }
             }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= len; i++){
        // cout << dp[i] << endl;
        if (dp[i] > ans)
           ans = dp[i];
    }
    if (ans == 1) return 0;
    else return ans;
}

int main() {
    string s = "(()";
    cout << longestValidParentheses(s);
    cin.get();
} 

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> dp(s.size(), 0);
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) {
                    continue;
                }
                int start = stk.top();
                stk.pop();
                dp[i] = i - start + 1;
                if (start > 1) {
                    dp[i] += dp[start - 1];
                }
                if (dp[i] > result) {
                    result = dp[i];
                }
            }
        }
        return result;
    }
};