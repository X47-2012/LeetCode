#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


vector<int> findSubstring(string S, vector<string> &L)
{
	vector<int> result;
	map<string, int> word_map;
	int sl = S.size();
	int N = L.size();
	if(N == 0 || sl == 0) return result;

	int wl = L[0].size();
	
	for(int i = 0; i < N; i++)
	{
		if(word_map.find(L[i]) == word_map.end())
			word_map[L[i]] = 1;
		else
			word_map[L[i]] = word_map[L[i]] + 1;
	}

	for(int i = 0; i <= sl - N * wl; i++)
	{
		map<string, int> word_map_tmp(word_map);
		bool flag = true;
		for(int j = 0; j < N; j++)
		{
			string tmp = S.substr(i + j * wl, wl);
			//cout<<tmp<<endl;
			if(word_map_tmp.find(tmp) != word_map_tmp.end() && word_map_tmp[tmp] > 0)
				word_map_tmp[tmp] = word_map_tmp[tmp] - 1;
			else
			{
				flag = false;
				break;
			}
		}
		if(flag) result.push_back(i);
	}

	return result;
}

int main()
{
	string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> L;
	L.push_back("fooo");
	L.push_back("barr");
	L.push_back("wing");
	L.push_back("ding");
	L.push_back("wing");
	
	vector<int> result = findSubstring(S, L);
	for(int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
}