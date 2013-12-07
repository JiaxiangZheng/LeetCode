class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = ((left + right) >> 1);
            if (A[mid] == target) return mid;
            
            if (A[left] <= A[mid]) {
                if (A[mid] > target && A[left] <= target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (A[mid] < target && A[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

