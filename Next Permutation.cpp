#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int size = nums.size();
	if (size <= 1) return;
	
	int last = 0;
	for (int i = 1; i < size; i++) {
		if (nums[i] > nums[i - 1]) last = i;
	}
	
	if (last == 0) {
		sort(nums.begin(), nums.end());
	} else {
		int i;
		for (i = last; i < size; i++) {
			if (nums[i] <= nums[last - 1]) break;
		}
		
		int tmp = nums[last - 1];
		nums[last - 1] = nums[i - 1];
		nums[i - 1] = tmp;
		sort(nums.begin() + last, nums.end());
	}
}

int main() {
	int myints[] = {1, 5, 1};
	vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
	nextPermutation(vec);
	
	for (int i = 0; i < vec.size(); i++) cout << vec[i] <<" ";
	cin.get();
}
