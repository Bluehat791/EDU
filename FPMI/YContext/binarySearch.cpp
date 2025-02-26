#include<iostream>
#include<algorithm>

int binarysearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size-1;
    while (left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid] == target)
        {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {1,5,2,6,3,7,44,76,25,90};

    std::sort(arr,arr+10);
    
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << arr[i] << "\n";
    }

    std::cout << binarysearch(arr,10,6) << "\t target index";
}