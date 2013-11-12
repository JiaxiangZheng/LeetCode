#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*
 * 从右向左找出第一个满足a[i-1] < a[i]的i
 * 从右向左找出第一个满足a[j] >= a[i-1]的j
 * 将a[i-1]与a[j]交换
 * 逆序重新排列a[i...end]
 */
// Assume that all elements in arr is different
bool has_next_permutation(std::vector<int>& arr) {
    int i = arr.size() - 1, j = arr.size() - 1;
    if (i < 1) return false;
    for (; i > 0 && arr[i] < arr[i-1]; --i);
    if (i == 0) return false;
    // assert (arr[i-1] < arr[i]);
    for (; j >= 0 && arr[j] < arr[i-1]; --j);
    std::swap(arr[i-1], arr[j]);
    std::reverse(arr.begin() + i, arr.end());
    return true;
}

void all_permu(std::vector<int>& output, std::vector<int>& arr, int i) {
    if (i == arr.size()) {
        for (int i=0; i<output.size(); ++i) {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    } 
    all_permu(output, arr, i+1);        //  不选 
    output.push_back(arr[i]);
    all_permu(output, arr, i+1);
    output.pop_back();
    return;
}
int main() {
    int array[3] = {0, 1, 2};
    std::vector<int> arr(array, array+3);
    std::vector<int> output;
    all_permu(output, arr, 0);
    return 0;
}
