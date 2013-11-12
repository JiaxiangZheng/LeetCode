int upper_bound(int A[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (A[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    return right + 1;
}
int lower_bound(int A[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (A[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return right + 1;
}
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos_l = lower_bound(A, n, target);
        int pos_r = upper_bound(A, n, target);
        std::vector<int> res(2, -1);
        if (A[pos_l] != target) return res;
        res[0] = pos_l; res[1] = pos_r - 1;
        return res;
    }
};

