#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
int size = nums.size();
    
    int start = 0;
    int l = 0;
    int r = size - 1;
    
    while (start != r && nums[start] == nums[r]) {
        start++;
    }
    
    l = start;
    while (l <= r) {
          int mid = (int) (l + r) / 2;
          if (nums[mid] == target) return true;
          
          if (nums[mid] > nums[size - 1]) {
             if (nums[mid] < target) {
                l = mid + 1; 
             } else {
                if (target >= nums[start]) {
                   l = start;
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
                   l = start;
                   r = mid - 1;           
                } else {
                  l = mid + 1;     
                } 
             }
          } 
    }
    return false;
}

int main() {
    int myints[] = {4, 5, 6, 7, 0, 1, 2, 3};
    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int));
    cout << search(vec, 0);
    cin.get();
}
