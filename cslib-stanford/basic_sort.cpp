#include "basic_sort.h"

#include <vector>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <ctime>
using namespace std;

void select_sort(int* arr, int n) {
    for (int i=0; i<n; ++i) {
        int minindex = i;
        for (int j=i+1; j<n; ++j) {
            if (arr[minindex] > arr[j]) minindex = j;   
        }
        if (minindex != i) {
            swap(arr[i], arr[minindex]);
        }
    }
    return;
}
void insert_sort(int* arr, int n) {
    for (int i=1; i<n; ++i) {
        int pivot = arr[i], j = i;
        while (j > 0 && arr[j-1] > pivot) {
            arr[j] = arr[j-1]; --j;
        }
        arr[j] = pivot;
    }
    return;
}

void quick_sort(int* arr, int n) {
    if (n <= 1) {
        return;
    }
    std::swap(arr[rand() % n], arr[0]);
    int last = 0;
    for (int i=1; i<n; ++i) {
        if (arr[i] < arr[0]) std::swap(arr[++last], arr[i]);
    }
    std::swap(arr[0], arr[last]);
    quick_sort(arr, last);
    quick_sort(arr+last+1, n-last-1);
}
static void _merge(int* arr, int m, int n) {
    std::vector<int> arr_l(arr, arr+m);
    std::vector<int> arr_r(arr+m, arr+n);
    n -= m;
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr_l[i] <= arr_r[j]) arr[k++] = arr_l[i++];
        else arr[k++] = arr_r[j++];
    }
    while (i < m) arr[k++] = arr_l[i++];
    while (j < n) arr[k++] = arr_r[j++];
    return;
}
void merge_sort(int* arr, int n) {
    if (n <= 1) return;
    int mid = n / 2;
    merge_sort(arr, mid);
    merge_sort(arr+mid, n - mid);
    _merge(arr, mid, n);
}

//void heap_sort(int *arr, int n) {   // construct a max-heap
//    int loop = (n >> 1) - 1;
//    for (int i=loop; i>0; --i) _sift_up(arr, i);
//}
//
//static void _sift_up(int* arr, int right) {
//    int c_index = right, p_index = (c_index-1) >> 1;
//    while (p_index >= 0 && arr[c_index] > p_index) {
//        std::swap(arr[c_index], arr[p_index]);
//        c_index = p_index;
//        p_index = (c_index-1) / 2;
//    }
//    return;
//}
//static void _sift_down() {
//
//}

int main() {
    const int N = 100;
    srand(time(NULL));
    std::vector<int> arr(N);
    for (int i=0; i<N; ++i) arr[i] = rand() % 2000;
    select_sort(&arr[0], N);
    std::copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
