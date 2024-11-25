#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void heapSort(int arr[], int n)
{
    vector<int> v(arr, arr+n);

    make_heap(v.begin(), v.end());

    sort_heap(v.begin(), v.end());

    copy(v.begin(),v.end(),arr);
}

int main()
{
    int arr[] = { 60, 20, 40, 70, 30, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}