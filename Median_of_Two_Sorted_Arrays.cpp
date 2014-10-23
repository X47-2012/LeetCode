#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <assert.h>
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


int findkth(int A[], int m, int B[], int n, int kth)
{
    assert(A!=NULL&&B!=NULL);
    assert(kth>=0&&kth<=m+n);

    if(m>n)
        return findkth(B, n, A, m, kth);
    if(m==0)
        return B[kth-1];
    if(kth==1)
        return min(A[0],B[0]);

    int pa=min(m,kth/2), pb=kth-pa;
    if(A[pa-1]<B[pb-1])
    {
        return findkth(A+pa, m-pa, B, n, kth-pa);
    }
    else if (A[pa-1]>B[pb-1])
    {
        return findkth(A, m, B+pb, n-pb, kth-pb);
    }
    else
    {
        return A[pa-1];
    }
}
double findMedianSortedArrays_2(int A[], int m, int B[], int n)
{
    assert(A!=NULL&&B!=NULL);
    if((m==0)&&(n==0))
        return 0;
    int k=m+n;
    if(k%2!=0)
        return (double)findkth(A, m, B, n, (k+1)/2);
    else
        return (double)(findkth(A, m, B, n, k/2)+findkth(A, m, B, n, k/2+1))/2;
}
int main()
{
    int A[]={1,2,3,4,5};
    int B[]={4,6,7};
    cout<<findMedianSortedArrays_2(A,5,B,3);
}
