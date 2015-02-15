#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

queue<char> q;
int left_num;
int right_num;

void help(vector<string> &ans, string str, int n)
{
	if(str.size() == 2 * n)
	{
		ans.push_back(str);
		return;
	}

	if(left_num < n)
	{
		left_num++;
		q.push('(');
		str.push_back('(');
		help(ans, str, n);
		left_num--;
		q.pop();
		str = str.substr(0, str.size() - 1);
	}

	if(right_num < n && (!q.empty() && q.front() == '('))
	{
		right_num++;
		q.pop();
		str.push_back(')');
		help(ans, str, n);
		right_num--;
		q.push('(');
		str = str.substr(0, str.size() - 1);
	}
}

vector<string> generateParenthesis(int n)
{
	//q.clear();
	left_num = 0;
	right_num = 0;
	vector<string> ans;
	string str;
	help(ans, str, n);
	return ans;
}

int main()
{
	/* code */
	vector<string> ans = generateParenthesis(3);
	for(int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
