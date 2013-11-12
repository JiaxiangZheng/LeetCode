/* 
 * An array with n elements which is K most sorted，就是每个element的初始位置
 * 和它最终的排序后的位置的距离不超过常数K，设计一个排序算法。It should be
 * faster than O(n*lgn)。 
 * */
/* 
 * 如果k比lgn要小的话，可以考虑用插入排序，这样每次插入的时候最多与前面K个元素比
 * 较而已。
 *
 * 这里是用最小堆来实现，先用前K个元素建立一个最小堆，以后每进来一个元素
 * 就弹出最小的值，这样把这些最小的值依次收集起来就必然是有序的了。最后一个堆中
 * 所有的元素直接用标准的排序算法即可。
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void sort(std::vector<int>& array_tobe_sorted, const int K) {
		std::priority_queue<int> min_k_heap;
		int i=0;
		for (; i<K; ++i)
			min_k_heap.push(array_tobe_sorted[i]);
		int pos = 0;
		for (; i<array_tobe_sorted.size(); ++i) {
			array_tobe_sorted[pos++] = min_k_heap.top();
			min_k_heap.pop();
			min_k_heap.push(array_tobe_sorted[i]);
		}
		for (; pos < array_tobe_sorted.size(); ++pos) {
			std::sort(array_tobe_sorted.begin()+pos, array_tobe_sorted.end(), std::less_equal<int>());
		}
		return;
    }
};
int main() {
	std::vector<int> Vs;
}
