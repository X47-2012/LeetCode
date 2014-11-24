#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if(strs.size() == 1)
        return strs[0];
    if(strs.size() == 0)
        return "";

    string re = "";
    for(int i = 0;;i++)
    {
        char tmp;
        if(i >= strs[0].size())
            return re;
        else
            tmp = strs[0][i];
        for(int j = 1; j < strs.size(); j++)
        {
            if(tmp != strs[j][i])
                return re;
        }
        re += tmp;
    }
    return re;
}

int main()
{
    vector<string> input;
    input.push_back("");
    input.push_back("b");
    //input.push_back("c");

    cout<<longestCommonPrefix(input);
}
