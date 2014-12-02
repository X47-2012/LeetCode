#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

char *letter[10];

void func(string &str, vector<string> &ans, string digits, int index)
{
    if(index == digits.size())
    {
        ans.push_back(str);
        return;
    }

    int num = digits[index] - '0';
    for(int i = 0; i < strlen(letter[num]); i++)
    {
        str += letter[num][i];
        func(str, ans, digits, index+1);
        str = str.substr(0, index);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    ans.clear();
    if(digits.size() == 0)
    {
        ans.push_back("");
        return ans;
    }

    letter[0] = " ";
    letter[1] = " ";
    letter[2] = "abc";
    letter[3] = "def";
    letter[4] = "ghi";
    letter[5] = "jkl";
    letter[6] = "mno";
    letter[7] = "pqrs";
    letter[8] = "tuv";
    letter[9] = "wxyz";

    string str;
    func(str, ans, digits, 0);
    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<endl;
}
