 //Harsh Bamotra AC-1216
//Program to sort an array using radix sort

#include <iostream>
using namespace std;

int Max(int arr[], int n)
    {
	int mx = arr[0];
	for (int i=1 ; i<n ; i++)
		if(arr[i]>mx)
			mx=arr[i];
	return mx;
    }

void countSort(int arr[] , int n , int ex)
    {
	int temp[n] , count[10] , i;
	
	for(int i=0 ; i<10 ; i++)
		count[i] = 0;
 
	for (i=0 ; i<n ; i++)
		count[(arr[i]/ex)%10]++;

	for (i=1 ; i<10 ; i++)
		count[i]+=count[i - 1];

	for (i=n-1 ; i>=0 ; i--) 
		{
			temp[count[(arr[i] / ex) % 10] - 1] = arr[i];
			count[(arr[i] / ex) % 10]--;
		}
	
	for (i=0 ; i<n ; i++)
		arr[i] = temp[i];
    }

void RadixSort(int arr[] , int n)
    {

	int m = Max(arr, n);

	for (int ex = 1; m / ex > 0; ex *= 10)
		countSort(arr, n, ex);
    }

int main()
    {
	int n;
	
	cout << "Enter the number of elements ::";
	cin >> n;

	int arr[n];

	cout << "Enter array the elements ::";
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];

	cout << endl << "************************************";
	cout << endl << "The array you entered ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	RadixSort(arr , n);
	
	cout << endl << "The array after sorting ::";	
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";
	cout << endl << "************************************";
	
	return 0;
    }