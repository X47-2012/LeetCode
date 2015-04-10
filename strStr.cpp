#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * compute_prefix_function(char * P)
{
	int m = strlen(P);
	int *next = new int[m + 1];
	next[0] = -1;
	int k = -1;
	int j = 0;
	while(j < m)
	{
		if(k == -1 || P[j] == P[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else k = next[k];
	}
	return next;
}

int strStr(char *haystack, char *needle)
{
	int n = strlen(haystack);
	int m = strlen(needle);

	if(n == 0 && m == 0)
		return 0;
	else if(n == 0 && m != 0)
		return -1;
	else if(n != 0 && m == 0)
		return 0;

	int *next = compute_prefix_function(needle);
	int i = 0;
	int j = 0;
	while(i < n)
	{
		if(j == -1 || haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else j = next[j];

		if(j == m)
		{
			delete[] next;
			next = NULL;
			return i - m;
		}
	}

	delete[] next;
	next = NULL;
	return -1;
}

int main()
{
	char * haystack = "abcdef";
	char * needle = "cde";

	printf("%d\n", strStr(haystack, needle));
}