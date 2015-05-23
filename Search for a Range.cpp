#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target, int mov) {
	int l = 0; int r = nums.size() - 1;
	while (l <= r) {
	    int mid = (int) (l + r) / 2;
		if (nums[mid] == target) {
 		    if (mid + mov < 0 || mid + mov >= nums.size() || nums[mid + mov] != target) return mid;
            else if (mov == -1) r = mid - 1;
            else l = mid + 1;
		} else if (nums[mid] < target) l = mid + 1;
		else r = mid - 1;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int l = search(nums, target, -1);
    if (l == -1) {
	    ans.push_back(-1);
		ans.push_back(-1); 
    } else {
        int r = search(nums, target, 1);
        ans.push_back(l);
        ans.push_back(r);
	}
    return ans;
}

int main() {
    int myints[] = {5, 6, 7, 8, 8, 10};
    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
	vector<int> ans = searchRange(vec, 4);
	cout << ans[0] << " " << ans[1];
	cin.get();
}
