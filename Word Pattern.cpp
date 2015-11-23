#include <map>
#include <iostream>
using namespace std;

bool wordPattern(string pattern, string str)
{
    map<string, char> record;
    string res = "";
    string tmp = "";
    int index = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        if (i == str.size() || str[i] == ' ')
        {
            if (record.find(tmp) == record.end())
            {
                res += ((char) 'a' + index);
                record[tmp] = (char) 'a' + index;
                index++;
            }
            else
            {
                res += record[tmp];
            }
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }

    record.clear();
    string pat = "";
    index = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (record.find("" + pattern[i]) == record.end())
        {
            pat += ((char) 'a' + index);
            record["" + pattern[i]] = (char) 'a' + index;
            index++;
        }
        else
        {
            pat += record["" + pattern[i]];
        }
    }
    cout << res << " " << pat << endl;
    return res == pat;
}

int main()
{
    cout << wordPattern("cccc", "dog dog dog dog");
}
