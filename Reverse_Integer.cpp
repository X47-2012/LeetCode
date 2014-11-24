#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

int reverse(int x)
{
    const int MAX_INT = ((unsigned)(-1)>>1);
    //cout<<MAX_INT<<endl;
    const int MIN_INT = (~MAX_INT);
    //cout<<MIN_INT<<endl;
    int re=0;
    while(x!=0)
    {
        int tmp=x%10;

        if(re>MAX_INT/10 || re<MIN_INT/10)
            return 0;
        if(tmp>0)
            if(re*10>MAX_INT-tmp)
                return 0;
        if(tmp<0)
            if(re*10<MIN_INT-tmp)
                return 0;

        re=re*10+tmp;
        x=(int)x/10;
    }
    return re;
}

int main()
{
    cout<<reverse(-123050)<<endl;
}
