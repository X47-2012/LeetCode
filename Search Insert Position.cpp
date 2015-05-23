#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0; int r = nums.size();
	while (l < r) {
        int mid = (int) (l + r) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) l = mid + 1;
		else r = mid;	  
    }
    return l;
}

int main() {
    int myints[] = {5, 7, 7, 8, 8, 10};
    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
	int ans = searchInsert(vec, 12);
	cout << ans;
	cin.get();
}
