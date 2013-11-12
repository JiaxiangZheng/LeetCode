class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = ((left + right) >> 1);
            if (A[mid] == target) return true;
            if (A[left] < A[mid]) {
                if (target < A[mid] && A[left] <= target) right = mid - 1; 
                else left = mid + 1;
            } else if (A[left] > A[mid]) {
                if (target > A[mid] && A[right] >= target) left = mid + 1; 
                else right = mid - 1;
            } else left++;
        }
        return false;
    }
};


