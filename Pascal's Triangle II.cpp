vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);
    long pre = 1;
    int mul_x = rowIndex, mul_y = 1;
    for (int i = 0, j = rowIndex; i <= j; i++, j--) {
        if (i == 0) {
            ans[i] = ans[j] = 1;
        } else {
            pre = pre * mul_x / mul_y; // avoid overflow
            ans[i] = ans[j] = pre;
            mul_x--;
            mul_y++;
        }
    }
    return ans; 
}