#include<stdio.h>
int linear_search(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==element)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int element)
{
    int low, mid, high;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (high+low)/2;
        if(arr[mid]==element)
            return mid;
        else if(arr[mid]<element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
 
int main()
{
    int arr[] = {1,5,3,2,7,9};
    int size = sizeof(arr)/sizeof(int);
    int element = 7;
    // int index = linear_search(arr,size,element);
    int index2 = binary_search(arr, size, element);
    // printf("Element %d is found at index %d\n", element, index);
    printf("Element %d is found at index %d\n", element, index2);
    return 0;
}