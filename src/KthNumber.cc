/* 
 * Author : jiaxiang.zheng135@gmail.com
 * Date   : 2012/10/16
 */
#include <queue>
#include <vector>
#include <iostream>
using std::priority_queue;
class Solution
{
public:
    virtual int solve(const std::vector<int>& arr, int K) = 0;
};
class Solution1 : public Solution
{
public:
   int solve(const std::vector<int>& arr, int K)
   {
       priority_queue<int, std::vector<int>, std::greater<int>> pQ;
       for (int i=0; i<arr.size(); ++i)
       {
            if (i<K) pQ.push_back(arr[i]);
            else {
                if (pQ.top() < arr[i]) continue;
                pQ.pop();
                pQ.push(arr[i]);
            }
       }
       return pQ.top();
   }
};
class Solution2 : public Solution
{
public:
    /* To be edit using quick-sort partition algorithm
     * Average time can be achieved to O(n)
     */
    int solve(const std::vector<int>& arr, int K)
    {
        int* copy_arr = new int[arr.size()];
        memcpy(copy_arr, &arr[0], arr.size()*sizeof(int));
        kthSelect(copy_arr, K, 0, arr.size()-1);
        int out = copy_arr[K];
        delete []copy_arr;
        return out;
    }
private:
    bool kthSelect(int arr[], int K, int _left, int _right)
    {
        if (K > _right || K < _left) return false;

        std::swap(arr[_left + rand()%(_right-_left+1)], arr[_right]);
        int pivot = arr[_right];	//add the selection before
        int i = _left;
        int j = _right-1;

        while (1)
        {
            while(arr[i] < pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if (i < j)
                swap(arr[i], arr[j--]);	//a[i] <= a[j]
            else
                break;
        }
        swap(arr[i], arr[_right]);

        if (i == K)
            return true;
        else if (i > K)
            return kthSelect(arr, K, _left, i-1);
        else return kthSelect(arr, K, i+1, _right);
    }
};


int main()
{
	//srand(time(NULL));
	const int SIZE_ARR = 100000;
	std::vector<int> vInts(SIZE_ARR);
	int testCount = 10;
	while (testCount--)
	{
		for_each(vInts.begin(), vInts.end(), [](int& val){val=rand()%65535;});
		//std::copy(vInts.begin(), vInts.end(), std::ostream_iterator<int>(cout, " "));	std::cout << endl;
		int K = rand() % SIZE_ARR;
		kthSelect(&vInts[0], K, 0, SIZE_ARR-1);
		int pivot = vInts[K];
		fprintf(stdout, "%d\t%d", K, vInts[K]);
	 	std::sort(vInts.begin(), vInts.end(), std::less<int>());
		// assert(vInts[K] == pivot);
		fprintf(stdout, "\t%d\n", vInts[K]);
	}
	return 0;
}

