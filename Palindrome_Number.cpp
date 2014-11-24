#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    int base = 1;
    while(x/base >= 10)
        base *= 10;
    while(x != 0)
    {
        int leftdigit = x / base;
        int rightdigit = x % 10;
        if(leftdigit != rightdigit)
            return false;
        x -= leftdigit * base;
        x /= 10;
        base /= 100;
    }
    return true;
}

