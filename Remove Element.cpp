#include <iostream>
using namespace std;

int removeElement(int A[], int n, int elem)
{
    if(A == NULL || n == 0)
        return 0;
	int i = 0;
	int j = 0;
	while(1)
	{
		if(A[j] != elem)
		{
			A[i++] = A[j++];
		}
		else j++;
		if(j >= n)
			break;
	}
	return i;
}

int main()
{
	int num[] = {1, 1, 2};
	int n = removeElement(num, 3, 3);
	for(int i = 0; i < n; i++)
		cout<<num[i]<<" ";
}
