//Program Runtime: 12 milli secs
//Program Runtime: 68 milli secs

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int len = rows * cols;
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = ((left + right) >> 1);
            int row = mid / cols, col = mid % cols;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) {
                right = mid - 1;
            } else left = mid + 1;
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) return false;

        int left = 0, right = matrix.size() - 1;        // 找所在的行
        while (left <= right) {
            int mid = ((left + right) >> 1);
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        if (right == -1) return false;
        int row = left-1;

        left = 0, right = matrix[row].size() - 1;       // 找所在的列
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

