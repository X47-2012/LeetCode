#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWords(string &s)
{
    vector<string> vec;
    string tmp = "";
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            if (tmp.size() != 0)
            {
                vec.push_back(tmp);
                tmp = "";
            }
            i++;
            while (s[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            tmp += s[i];
            i++;
        }
    }
    if (tmp.size() != 0)
        vec.push_back(tmp);

    s.clear();
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        s += vec[i];
        if (i != 0)
            s += " ";
    }
}

int main()
{
    string s = "I am a boy";
    reverseWords(s);
    cout << s;
}
