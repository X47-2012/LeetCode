#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    uint32_t base = 2147483648;
    while (n != 0)
    {
        int bit = n % 2;
        ans += (base * bit);
        n = n / 2;
        base = base / 2;
    }
    return ans;
}

int main() {
    cout << reverseBits(2);
}
