//Binary search using Iterative and recursive method
#include<stdio.h>

//iterative method
int iterativeM(int arr[], int key, int low, int high)
{
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==key)
			return mid;
		else if (arr[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

//Recursive Method
int RecM(int arr[],int key, int low, int high)
{
	if (low > high) 
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return RecM(arr, key, low, mid - 1);
    else
        return RecM(arr, key, mid + 1, high);
}
int main()
{
	int n,key;
	printf("Enter size of the array :");
	scanf("%d",&n);
	int arr[n];
	printf("Enter element of the array :");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to search :");
	scanf("%d",&key);
	
	printf("\nUsing Iterative Binary Search Method\n");
	printf("======================================\n");
	int flag=iterativeM(arr,key,0,n-1);
	if(flag == -1)
		printf("Element %d is not present in the array",key);
	if(flag>0)
		printf("Element %d found at position %d\n",key,flag+1);
		
	printf("\nUsing Recursive Binary Search Method\n");
	printf("======================================\n");
	int t=RecM(arr,key,0,n-1);
	if(t == -1)
		printf("Element %d is not present in the array",key);
	if(t>0)
		printf("Element %d found at position %d\n",key,t+1);
}
