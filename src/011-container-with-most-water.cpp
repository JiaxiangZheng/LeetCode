/* 暴力求解会超时
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> areas(height.size() - 1);
        for (int i=0; i<height.size()-1; ++i) {
            areas[i] = -1;
            for (int j=i+1; j<height.size(); ++j) {
                int a = (j-i)*min(height[j], height[i]);
                if (areas[i] < a) areas[i] = a;
            }
        }
        int max_area = -1;
        for (int i=0; i<areas.size(); ++i) max_area = std::max(max_area, areas[i]);
        return max_area;
    }
};

/* 这里的思路是每次当height[i] < heigh[j]时，height[i]就成了短板，因为再将j往里移动
 * 不会再增加面积了，所以只能将i往里移动才有可能增加面积。
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() < 2) return 0;
        int i = 0, j = height.size() - 1;
        int max_area = 0;
        while (i < j) {
            int curarea = 0;
            if (height[i] < height[j]) {
                area = height[i] * (j - i);
                ++i;
            } else {
                area = height[j] * (j - i);
                --j;
            }
            if (max_area < area) area = max_area;
        }
        return max_area;
    }
};
