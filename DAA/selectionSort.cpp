//----------Selection Sort--------------//
#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>& arr, int n)
{
	for(int i=0; i<=n-2; i++)
	{
		int mini=i;
		for(int j=i; j<=n-1; j++)
		{
			if(arr[j]<arr[mini])
				mini=j;
		}
		int temp=arr[i];
		arr[i]=arr[mini];
		arr[mini]=temp;
	}
}
int main()
{
	int n;
	cout<<"Enter number of element :"<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter array element :"<<endl;
	for(int i=0; i<n; i++)
	{
		cin >>arr[i];
	}
	selectionSort(arr,n);
	cout<<"After using Selection Sort :"<<endl;
	for(int i=0; i<n; i++)
	{
		cout << arr[i]<<" ";
	}
	return 0;
}



