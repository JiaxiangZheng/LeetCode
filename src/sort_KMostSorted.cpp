/* 
 * An array with n elements which is K most sorted������ÿ��element�ĳ�ʼλ��
 * �������յ�������λ�õľ��벻��������K�����һ�������㷨��It should be
 * faster than O(n*lgn)�� 
 * */
/* 
 * ���k��lgnҪС�Ļ������Կ����ò�����������ÿ�β����ʱ�������ǰ��K��Ԫ�ر�
 * �϶��ѡ�
 *
 * ����������С����ʵ�֣�����ǰK��Ԫ�ؽ���һ����С�ѣ��Ժ�ÿ����һ��Ԫ��
 * �͵�����С��ֵ����������Щ��С��ֵ�����ռ������ͱ�Ȼ��������ˡ����һ������
 * ���е�Ԫ��ֱ���ñ�׼�������㷨���ɡ�
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
