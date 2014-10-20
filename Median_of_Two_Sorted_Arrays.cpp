#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

double findMedianSortedArrays_1(int A[], int m, int B[], int n)
{
    if((m==0)&&(n==0))
        return 0;

    int k=(int)((m+n)/2+1);
    int* tmp=new int[k];
    int x=0,y=0;
    for(int i=0;i<k;i++)
    {
        if(x>=m&&y<n)
        {
            tmp[i]=B[y];
            y++;
            continue;
        }
        if(x<m&&y>=n)
        {
            tmp[i]=A[x];
            x++;
            continue;
        }

        if(A[x]<=B[y])
        {
            tmp[i]=A[x];
            x++;
        }
        else
        {
            tmp[i]=B[y];
            y++;
        }
    }
    if((m+n)%2==0)
    {
        return (double)(tmp[k-1]+tmp[k-2])/2;
    }
    else
        return tmp[k-1];
}

double findMedianSortedArrays_1(int A[], int m, int B[], int n)
{
    if((m==0)&&(n==0))
        return 0;

}
int main()
{
    int A[]={};
    int B[1]={1};
    cout<<findMedianSortedArrays_1(A,0,B,1);
}
