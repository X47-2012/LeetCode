#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p)
{
    int cnt;
    for (int i = 0; i < p.size(); i++)
        if (p[i] != '*')
            cnt++;
    if (cnt > s.size())
        return false;

    vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1));
    dp[0][0] = true;
    for (int i = 1; i <= s.size(); i++)
        dp[i][0] = false;

    bool flag = true;
    for (int j = 1; j <= p.size(); j++)
    {
        if ((p[j - 1] == '*') && (flag == true))
            dp[0][j] = true;
        else
        {
            dp[0][j] = false;
            flag = false;
        }
    }

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= p.size(); j++)
        {
            if (p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                bool flag = false;
                for (int k = 0; k <= i; k++)
                {
                    flag |= dp[k][j - 1];
                    if (flag == true)
                        break;
                }
                dp[i][j] = flag;
                while (true)
                {
                    j++;
                    if (p[j - 1] == '*')
                        dp[i][j] = flag;
                    else
                        break;
                }
                j--;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] & (s[i - 1] == p[j - 1]);
            }
        }
    }

    return dp[s.size()][p.size()];
}

int main()
{
    string s = "abc";
    string p = "a****dc";
    cout << isMatch(s, p);
}
