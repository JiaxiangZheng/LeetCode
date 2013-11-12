struct Cmp {
public:
    Cmp(std::vector<int>& numbers) : num(numbers) {} 
    bool operator() (int a, int b) {
        return num[a] < num[b];
    }
private:
    std::vector<int>& num;
};
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> indexs(numbers.size());
        for (int i=0; i<indexs.size(); ++i) indexs[i] = i;
        Cmp cmp(numbers);
        std::sort(indexs.begin(), indexs.end(), cmp);
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[indexs[i]] + numbers[indexs[j]];
            if (sum == target) break;
            else if (sum > target) --j;
            else ++i;
        }
        std::vector<int> out;
        out.push_back(std::min(indexs[i], indexs[j]) + 1);
        out.push_back(std::max(indexs[i], indexs[j]) + 1);
        return out;
    }
};



