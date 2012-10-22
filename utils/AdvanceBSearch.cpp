#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
using namespace std;

template <typename T>
unsigned int bsearchVal(const std::vector<T>& arr, unsigned int _left, unsigned int _right, T val)
{
    while (_left <= _right)
    {
        unsigned int _middle = _left + (_right - _left)/2;
        if (arr[_middle] == val)  return _middle;
        else if (arr[_middle] > val)
            _right = _middle - 1;
        else _left = _middle + 1;
    }
    return -1;//positive useless value
}
template <typename T>
inline bool inorder(const std::vector<T>& arr, unsigned int _left, unsigned int _right)
{
    return arr[_left] <= arr[_right];
}
template <typename T>
unsigned int searchVal(const std::vector<T>& arr, unsigned int _left, unsigned int _right, T val)
{
    if (inorder(arr, _left, _right))
        return bsearchVal(arr, _left, _right, val);

    unsigned int _middle = _left + (_right - _left)/2;

    if (inorder(arr, _left, _middle))
    {
        if (val >= arr[_left] && val <= arr[_middle])
            return bsearchVal(arr, _left, _middle, val);
        else return searchVal(arr, _middle+1, _right, val);
    } else {
        if (val >= arr[_middle] && val <= arr[_right])
            return bsearchVal(arr, _middle, _right, val);
        else return searchVal(arr, _left, _middle-1, val);
    }
    return -1;
}
template <typename T>
unsigned int searchVal(const std::vector<T>& arr, T val)
{
	if (!checkData(arr))
		return -1;
	return searchVal(arr, 0, arr.size()-1, val);
}
/*  checkData checks if the arr is rotated by an ordered sequence
 */
template <typename T>
bool checkData(const std::vector<T>& arr)
{
	bool flag = true;
	//TO BE IMPLEMENTED...
	return flag;
}

int main()
{
    int N = 1000;
    std::vector<int> arr;
    arr.reserve(N);

    for (int i=0; i<N; ++i)
        arr.push_back(i+1);

    srand(time(NULL));
    int k=rand()%N;
    std::cout << k << std::endl;
    std::reverse(arr.begin(), arr.begin()+k);
    std::reverse(arr.begin()+k, arr.end());
    std::reverse(arr.begin(), arr.end());
//	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, " "));

	for (int i=0; i<arr.size(); ++i)
	{
		int _index = rand()%N;
		int index = searchVal(arr, arr[_index]);
		assert(index == _index);
	    std::cout << index << endl;
	}
    return 0;
}
