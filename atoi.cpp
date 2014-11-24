#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int atoi(const char *str)
{
    const int MAX_INT = ((unsigned)(-1)>>1);
    const int MIN_INT = (~MAX_INT);

    if(str == NULL || strlen(str) == 0)
        return 0;
    int length = strlen(str);
    int i = 0;
    while(str[i]==' ' || str[i]=='\t')
    {
        i++;
        if(i >= length)
            return 0;
    }
    char sign = str[i];

    if(sign == '-' || sign == '+')
    {
        if(length == 1)
            return 0;
        i++;
    }

    int num = 0;
    for(;i<strlen(str);i++)
    {
        if(str[i]<'0' || str[i]>'9')
            break;
        int tmp = str[i] - '0';
        if(sign == '-')
        {
            if(num < MIN_INT/10)
                return MIN_INT;
            if(num*10 < MIN_INT+tmp)
                return MIN_INT;
            num = num * 10 -tmp;
        }
        else
        {
            if(num > MAX_INT/10)
                return MAX_INT;
            if(num*10 > MAX_INT-tmp)
                return MAX_INT;
            num = num * 10 + tmp;
        }
    }
    if(abs(num) == 0)
        return 0;
    else
        return num;
}

int main()
{
    cout<<atoi("+")<<endl;
}
