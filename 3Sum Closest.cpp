#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &num, int target)
{
    const int MAX_INT = ((unsigned)(-1)>>1);

    sort(num.begin(), num.end());
    int min_ans = 0;
    int min_val = MAX_INT;
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
            if(num[i] + num[left] + num[right] < target)
            {
                int val = target - (num[i] + num[left] + num[right]);
                if(val < min_val)
                {
                    min_val = val;
                    min_ans = num[i] + num[left] + num[right];
                }
                left++;
            }
            else if(num[i] + num[left] + num[right] > target)
            {
                int val = (num[i] + num[left] + num[right]) - target;
                if(val < min_val)
                {
                    min_val = val;
                    min_ans = num[i] + num[left] + num[right];
                }
                right--;
            }
            else
            {
                min_ans = target;
                min_val = 0;
                left++;
                right--;
            }
        }
    }
    return min_ans;
}

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(1);
    in.push_back(-1);
    in.push_back(-1);
    in.push_back(3);
    cout<<threeSumClosest(in, 1);
}
