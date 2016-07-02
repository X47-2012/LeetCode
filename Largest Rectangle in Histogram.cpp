class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int i = 0;
        int result = 0;
        while (i <= heights.size()) {
            if (stk.empty() || (i != heights.size() && heights[i] > heights[stk.top()])) {
                stk.push(i++);
            } else {
                int curH = heights[stk.top()];
                stk.pop();
                int lo = stk.empty() ? -1 : stk.top();
                result = max(result, curH * (i - lo - 1));
            }
        }
        return result;
    }
};