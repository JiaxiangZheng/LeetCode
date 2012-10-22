#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Merge(int *arr1, int left, int mid, int right);

void MergeSort(int arr[], int left, int right)
{
    if (left == right) return;//only one element
    int mid = (left+right)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, right);
}

void Merge(int *arr1, int left, int mid, int right)
{//arr1 and arr2 is already sorted , output the result to arr1 
    int i=left, j=mid+1;
    int k = 0;
    int *arr = new int[right-left+1];
    while (i<=mid && j<=right)
    {
        if (arr1[i] <= arr1[j])
            arr[k] = arr1[i++];
        else arr[k] = arr1[j++];
        ++k;
    }
    
    while (i<=mid)
        arr[k++] = arr1[i++];
    while (j<=right)
        arr[k++] = arr1[j++];
    for (int i=0; i<k; ++i){
        arr1[left+i] = arr[i];
    }
    delete[] arr;
    return;
}


int main()
{
    int arr[100];
//    vector<int>  V(100);
//    for (int i=0; i<=50; ++i){
//        arr[i] = 2*i+1;
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
//    for (int i=51; i<100; ++i){
//        arr[i] =2* (i-51);
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
//    Merge(arr, 0, 50, 99);
//    for (int i=0; i<100; ++i)  {
//        cout << arr[i] << "\t";
//    }


    vector<int> V;
    V.reserve(100);
    for (int i=0; i<100; ++i)
        V.push_back(i);
    random_shuffle(V.begin(), V.end());
    for (int i=0; i<100; ++i)  {
        arr[i] = V[i];
        cout << arr[i] << "\t";
    }
    cout << endl << endl;
    MergeSort(arr, 0, 99);
    for (int i=0; i<100; ++i)  {
        cout << arr[i] << "\t";
    }
    cout << endl;


    getchar();
    return 0;
}
