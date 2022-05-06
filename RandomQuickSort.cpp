 //Harsh Bamotra AC-1216
//Program to implement randomize quick sort

#include <iostream>
#include <cstdlib> 
#include <time.h>
int count=0;
using namespace std;

template <class T>
int partition(T arr[] , int p , int r)
    {
	T x = arr[r];
	int i = p-1;

	for(int j=p ; j<r ; j++)
		{
			count++;
			if(arr[j]<=x)
				{
					i++;
					swap(arr[i] , arr[j]);
				}
		}
	swap(arr[i+1] , arr[r]);
	return (i+1);
    }

template <class T>
randomize_partition(T arr[] , int p , int r)
    {
	srand(time(NULL));
	int i = (int) p+(rand()%(r-p+1));
	swap(arr[r] , arr[i]);
	return partition(arr , p , r);
    }

template <class T>
void QuickSort(T arr[] , int p , int r)
    {
	if(p<r)
		{
			int q = randomize_partition(arr , p , r);
			QuickSort(arr , p , q-1);
			QuickSort(arr , q+1 , r);
		}
    }

int main()
    {
	int n;
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

	QuickSort<int>(arr , 0 , n-1);	

	cout << endl << "The array after sorting ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << endl << "Number of comparisons ::" << count;
	cout << endl<< "**********************************************" << endl;
	return 0;
    }