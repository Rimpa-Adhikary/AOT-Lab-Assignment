#include<stdio.h>
void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for(i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
        printarray(arr, n);
    }
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Initial array \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array \n");
    insertionSort(arr, n);
    return 0;
}
