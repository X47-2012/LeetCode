#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_prefix_function(char * P) {
	int m = strlen(P);
	int *next = new int[m + 1];
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < m) {
		if (k == -1 || P[j] == P[k]) {
			k++;
			j++;
			next[j] = k;
		}
		else k = next[k];
	}
	return next;
}

int strStr(char *haystack, char *needle) {
	int n = strlen(haystack);
	int m = strlen(needle);

	if (n == 0 && m == 0)
		return 0;
	else if (n == 0 && m != 0)
		return -1;
	else if (n != 0 && m == 0)
		return 0;

	int *next = compute_prefix_function(needle);
	int i = 0;
	int j = 0;
	while (i < n) {
		if (j == -1 || haystack[i] == needle[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}

		if(j == m) {
			delete[] next;
			next = NULL;
			return i - m;
		}
	}

	delete[] next;
	next = NULL;
	return -1;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
			return 0;
		}
		int N = haystack.size() - needle.size() + 1;
		for (int i = 0; i < N; i++) {
			int j = i, k = 0;
			while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
				j++; k++;
			}
			if (k == needle.size()) {
				return i;
			}
		}
		return -1;
    }
};

class Solution {
public:
	static vector<int> compute_prefix(const string &pattern) {
		vector<int> next(pattern.size(), 0);
		next[0] = -1;
	}
	
	static int kmp(const string &text, const string &pattern) {
		int n = text.size();
		int m = pattern.size();
		if (m == 0) { return 0; }
		
		vector<int> next = compute_prefix(pattern);
		int i = 0, j = 0;
		while (i < n) {
			if (j == -1 || text[i] == pattern[j]) {
				i++; j++;
			} else {
				j = next[j];
			}
			if (j == m) {
				return i - j;
			}
		}
		return -1;
	}
	
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};

int main()
{
	char * haystack = "abcdef";
	char * needle = "cde";

	printf("%d\n", strStr(haystack, needle));
}