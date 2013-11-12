// (link):[http://people.csail.mit.edu/bdean/6.046/dp/]
#include <cstdio>
#include <algorithm>
using namespace std;

float mvcs(float* arr, int len) {
    // S[i] denotes the maximum continuous sequence 
    // B[i] denotes the maximum continuous sequence that contains arr[i]
    float S = 0.0f, B = 0.0f;   

    for (int i=0; i<len; ++i) {
        B = max(arr[i], B+arr[i]);
        S = max(S, B);
    }
    return S;
}

int main() {
    float arr[10] = {3, -1, 0, 2, 1, -2, 4, 7, -8, 3};
    printf("%f\n", mvcs(arr, 10));
    return 0;
}
