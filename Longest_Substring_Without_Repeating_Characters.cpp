#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <assert.h>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    set<char> hs;
    hs.clear();

    int max_len=0, i=0, j=0;
    for(;j<s.length();j++)
    {
        while(hs.find(s[j])!=hs.end())
        {
            hs.erase(s[i]);
            i++;
        }
        hs.insert(s[j]);
        max_len=max(max_len, j-i+1);
    }
    return max_len;
}

int main()
{
    string s="abcabcbb";
    cout<<lengthOfLongestSubstring(s);
}
