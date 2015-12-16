#include <iostream>
using namespace std;

int maxProduct(vector<int>& nums) {
	if (nums.size() == 0) {
		return 0;
	} else if (nums.size() == 1) {
		return nums[0];
	}

	int posMax, negMin, maxVal;
	maxVal = posMax = negMin = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		int tmp = negMin;
		negMin = min(posMax * nums[i], min(negMin * nums[i], nums[i]));
		posMax = max(posMax * nums[i], max(tmp * nums[i], nums[i]));

		if (posMax > maxVal) {
			maxVal = posMax;
		}
	}

	return maxVal;
}