#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    if (n <= 0) {
        return 0;
    }
    int water = 0, left = 0, right = n - 1;
    while (true) {
        int area = (right - left) * min(height[left], height[right]);
        if (area > water) {
            water = area;
        }
        if (height[left] <= height[right]) {
            int tmp = height[left];
            while (left + 1 < n && height[left + 1] <= tmp) {
                left++;
            }
            left++;
        } else {
            int tmp = height[right];
            while (right - 1 >= 0 && height[right - 1] <= tmp) {
                right--;
            }
            right--;
        }
        if (left >= right || left >= n || right < 0) {
            break;
        }
    }
    return water;
}
