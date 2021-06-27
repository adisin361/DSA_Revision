#include<stdio.h>

//insertion
int insert(int arr[], int n, int index, int k, int capacity)
{
    if(index>=capacity)
        return -1;
    for(int i=n-1; i>=index; i--)
        arr[i+1]=arr[i];
    arr[index]=k;
    return 0;
}

//deletion
int delete(int arr[], int n, int index, int capacity)
{
    if(index < 0 || index > n)
        return -1;
    for(int i=index; i<n-1; i++)
        arr[i]=arr[i+1];
    return 0;
}

//print 
void show(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[100] = {1,2,3,4};
    show(arr, 4);
    insert(arr, 5, 2, 67, 100);
    printf("\n");
    show(arr, 5);
    printf("\n");
    delete(arr, 5, 2, 100);
    show(arr, 4);
    return 0;
}