#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> numIndexMap;

    for (int i = 0; i < nums.size(); i++) {
        if (numIndexMap.find(nums[i]) == numIndexMap.end()) {
            numIndexMap[nums[i]] = i;
        } else {
            if (i - numIndexMap[nums[i]] <= k)
                return true;
            else
                numIndexMap[nums[i]] = i;
        }
    }
    return false;
}
