#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n)
{
    if(A == NULL || n == 0)
        return 0;
	int i = 0;
	int j = 0;
	while(1)
	{
		if(j == 0 || A[j] != A[j - 1])
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
	int num[] = {1, 1, 1, 2, 2, 3};
	int n = removeDuplicates(num, sizeof(num) / sizeof(int));
	for(int i = 0; i < n; i++)
		cout<<num[i]<<" ";
}
