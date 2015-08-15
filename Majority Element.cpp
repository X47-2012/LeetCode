#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int majoy;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majoy = nums[i];
            count = 1;
        }
        else
        {
            count += (majoy == nums[i]) ? 1 : -1;
        }
    }
    return majoy;
}
