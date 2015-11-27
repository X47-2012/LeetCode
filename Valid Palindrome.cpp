#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(string s)
{
    if (s.size() == 0)
        return true;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        while (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
        {
            i++;
            if (i == s.size())
                break;
        }
        while (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')))
        {
            j--;
            if (j == -1)
                break;
        }
        if (i == s.size() || j == -1)
            break;

        if ((s[i] - s[j] != 0) && (abs(s[i] - s[j]) != 32))
            return false;
    }
    return true;
}

int main()
{
    string str = "!!!";
    cout << isPalindrome(str);
}
