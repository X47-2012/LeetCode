#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int size = nums.size();
    int l = 0;
    int r = size - 1;
    
    while (l <= r) {
          int mid = (int) (l + r) / 2;
          if (nums[mid] == target) return mid;
          
          if (nums[mid] > nums[size - 1]) {
             if (nums[mid] < target) {
                l = mid + 1; 
             } else {
                if (target >= nums[0]) {
                   l = 0;
                   r = mid - 1;           
                } else {
                  l = mid + 1;       
                } 
             }
          } else {
              if (nums[mid] > target) {
                r = mid - 1; 
              } else {
                if (target > nums[size - 1]) {
                   l = 0;
                   r = mid - 1;           
                } else {
                  l = mid + 1;     
                } 
             }
          } 
    }
    return -1;
}

int main() {
    int myints[] = {4, 5, 6, 7, 0, 1, 2, 3};
    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
    cout << search(vec, 0);
    cin.get();
}
