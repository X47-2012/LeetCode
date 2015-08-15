#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A, E);
    int right = min(C, G);
    int bottom = max(B, F);
    int top = min(D, H);

    int mix;
    if (right - left <= 0 || top - bottom <= 0)
        mix = 0;
    else
        mix = (right - left) * (top - bottom);

    return (C - A) * (D - B) + (G - E) * (H - F) - mix;
}
