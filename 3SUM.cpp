#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int> > ans;
    ans.clear();

    sort(num.begin(), num.end());
    for(int i = 0; i < (int)num.size() - 2; i++)
    {
        if(i >= 1 && num[i] == num[i-1])
            continue;
        int left = i + 1;
        int right = num.size() - 1;
        while(left < right)
        {
            if(left > i + 1 && num[left] == num[left - 1])
            {
                left++;
                continue;
            }
            if(right < num.size()-1 && num[right] == num[right + 1])
            {
                right--;
                continue;
            }
            if(num[i] + num[left] + num[right] < 0)
                left++;
            else if(num[i] + num[left] + num[right] > 0)
                right--;
            else
            {
                vector<int> tmp;
                tmp.clear();
                tmp.push_back(num[i]);
                tmp.push_back(num[left]);
                tmp.push_back(num[right]);
                ans.push_back(tmp);
                left++;
                right--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> in;
    //in.push_back(0);
    //in.push_back(-1);
    //in.push_back(1);
    vector<vector<int> > ans = threeSum(in);
    /*for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }*/
}
