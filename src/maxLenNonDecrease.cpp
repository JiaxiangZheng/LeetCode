/*
 * return the maximum length of the non-decreasing elements in the arr
 */
int maxLenNonDecrease(int* arr, int len) {
    int* L = new int[len];
    L[0] = 1;
    for (int i=1; i<len; ++i) {
        L[i] = 1;
        for (int k=i-1; k>=0; --k) {
            if (arr[i] > arr[k]) {
                L[i] = MAX(L[k]+1, L[i]);
            }
        }
    }

    int maxLen = -1;
    for (int i=0; i<len; ++i)
        maxLen = MAX(maxLen, L[i]);
    delete[] L;
    return maxLen;
}

