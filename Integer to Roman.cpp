#include <stdlib.h>
#include <iostream>
using namespace std;

string intToRoman(int num)
{
    string single[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string ten[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundred[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousand[9] = {"M", "MM", "MMM"};

    string re = "";
    int base = 1;
    while(num/base >= 10)
        base *= 10;

    while(num > 0)
    {
        int tmp = num / base;
        if(tmp == 0)
        {
            base /= 10;
            continue;
        }
        if(base == 1000)
            re += thousand[tmp-1];
        if(base == 100)
            re += hundred[tmp-1];
        if(base == 10)
            re += ten[tmp-1];
        if(base == 1)
            re += single[tmp-1];
        num -= tmp * base;
        base /=10;
    }
    return re;
}

int main()
{
    cout<<intToRoman(10);
}
