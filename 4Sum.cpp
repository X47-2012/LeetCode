#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target)
{
    vector<vector<int> > ans;
    ans.clear();
    sort(num.begin(), num.end());

    for(int i = 0; i < (int)num.size() - 3; i++)
    {
        if(i >= 1 && num[i] == num[i-1])
            continue;

        for(int j = i + 1; j < (int)num.size() - 2; j++)
        {
            if(j > i + 1 && num[j] == num[j-1])
                continue;

            int left = j + 1;
            int right = num.size() - 1;
            while(left < right)
            {
                if(left > j + 1 && num[left] == num[left - 1])
                {
                    left++;
                    continue;
                }
                if(right < num.size()-1 && num[right] == num[right + 1])
                {
                    right--;
                    continue;
                }
                if(num[i] + num[j] + num[left] + num[right] < target)
                    left++;
                else if(num[i] + num[j] + num[left] + num[right] > target)
                    right--;
                else
                {
                    vector<int> tmp;
                    tmp.clear();
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[left]);
                    tmp.push_back(num[right]);
                    ans.push_back(tmp);
                    left++;
                    right--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(0);
    in.push_back(-1);
    in.push_back(0);
    in.push_back(-2);
    in.push_back(2);

    vector<vector<int> > ans = fourSum(in, 0);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
