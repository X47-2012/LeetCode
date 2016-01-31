int nthUglyNumber(int n) {
    int num[n];
    int factor2 = 2, factor3 = 3, factor5 = 5;
    int idx2 = 0, idx3 = 0, idx5 = 0;
    num[0] = 1;
    
    for (int i = 1; i < n; i++) {
        int tmp = min(factor2, min(factor3, factor5));
        num[i] = tmp;
        if (tmp == factor2) {
            factor2 = 2 * num[++idx2];
        }
        if (tmp == factor3) {
            factor3 = 3 * num[++idx3]; 
        }
        if (tmp == factor5) {
            factor5 = 5 * num[++idx5];
        }
    }
    return num[n - 1];
}