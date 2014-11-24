#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s)
{
    map<char, int> simbol;
    simbol['I'] = 1;
    simbol['V'] = 5;
    simbol['X'] = 10;
    simbol['L'] = 50;
    simbol['C'] = 100;
    simbol['D'] = 500;
    simbol['M'] = 1000;

    int re = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(i != s.size()-1)
        {
            if(simbol[s[i]] < simbol[s[i+1]])
                re -= simbol[s[i]];
            else
                re += simbol[s[i]];
        }
        else
            re += simbol[s[i]];
    }
    return re;
}

int main()
{
    cout<<romanToInt("MDCLXVI");
}
