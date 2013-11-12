// 最大连续子数组之和
int getSplitMaxValue(int *arr, int left, int mid, int right) {
    int leftMaxValue = arr[mid], rightMaxValue = arr[mid+1];
    for (int i=mid-1, sum = arr[mid]; i>=0; --i) {
        sum += arr[i];
        if (sum > leftMaxValue) leftMaxValue = sum;
    }
    if (right - mid >= 2) {
        for (int i=mid+2, sum = arr[mid+1]; i<=right; ++i) {
            sum += arr[i];
            if (sum > rightMaxValue) rightMaxValue = sum;
        }
    }
    return leftMaxValue + rightMaxValue;
}
int getMaxValue(int* arr, int left, int right) {
    if (left >= right) return arr[left];
    int mid = left + ((right - left) >> 1);
    int leftMaxValue  = getMaxValue(arr, left, mid);
    int rightMaxValue = getMaxValue(arr, mid+1, right);
    int splitMaxValue = getSplitMaxValue(arr, left, mid, right);
    splitMaxValue = splitMaxValue > leftMaxValue ? splitMaxValue : leftMaxValue;
    return splitMaxValue > rightMaxValue ? splitMaxValue : rightMaxValue;
}
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int dp_get_max_val(int *arr, int len) {
    int A = arr[0], S = arr[0];
    for (int i=1; i<len; ++i) {
        A = MAX(arr[i], arr[i]+A);
        S = MAX(A, S);
    }
    return S;
}

