 //Harsh Bamotra AC-1216
//Program to sort an array using merge sort

#include <iostream>
using namespace std;

template <class T>
int Merge(T arr[], int l, int h, int mid)
    {
	int m = mid-l+1, n=h-mid; 
		
	T A[m], B[n];

	for(int i=0 ; i<m; i++)
		A[i]=arr[l+i];
		
	for(int i=0; i<n; i++)
		B[i]=arr[mid+i+1];

	int i=0, j=0, k=l, com=0;
	while(i<m && j<n)
		{
			if(A[i]<=B[j])
				arr[k++]=A[i++];
			else 
				arr[k++]=B[j++];
			com++;
		}

	while(i<m)
		arr[k++]=A[i++];
	
	while(j<n)
		arr[k++]=B[j++];

	return com;
    }

template <class T>
int MergeSort(int l, int h, T arr[])
    {
	int m, com;
	if(l<h)
		{
			m=l+(h-l)/2;
			MergeSort(l, m, arr);
			MergeSort(m+1, h, arr);
			com+=Merge(arr, l, h, m);
		}
	return com;
    }

int main()
    {
	int n , count;
	cout << "Enter the number of elements ::";
	cin >> n;
	
	int arr[n];
	
	cout << "Enter the array elements ::" << endl;
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];
	
	cout << "**********************************************" << endl;

	cout << "The array you entered ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	count = MergeSort<int>(0 , n-1, arr);	

	cout << endl << "The array after sorting ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << endl << "Number of comparisons ::" << count;

	cout << endl<< "**********************************************" << endl;
	return 0;
    }