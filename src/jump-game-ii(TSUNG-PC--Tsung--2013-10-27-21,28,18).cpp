#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> jump(n, 99999);
        jump[0] = 0;
        for (int i=0; i<n; ++i) {
            printf("i = %d\n", i);
            for (int j=1; j<=A[i]; ++i) {
                jump[i+j] = std::min(jump[i+j], jump[i]+1);
                if (i+j == n-1) return jump[n-1]; 
            }
        }
        return jump[n-1];
    }
};
int main() {
    int A[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    Solution s;
    cout << s.jump(A, sizeof(A)/sizeof(int)) << endl;
    return 0;
}

