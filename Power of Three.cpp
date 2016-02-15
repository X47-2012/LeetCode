#include <iostream>
#include <cmath>
using namespace std;
/*
bool isPowerOfThree(int n) {
    if (n == 1) {
        return true;
    }
    if (n % 3 != 0 || n == 0) {
        return false;
    }
    return isPowerOfThree(n / 3);
} */

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    int m = log(INT_MAX) / log(3);
    int num = pow(3, m);
    return num % n == 0;
}

int main() {
    isPowerOfThree(27);
}


