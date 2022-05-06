 //Harsh Bamotra AC-1216
//Program to implement insertion sort

#include <iostream>
using namespace std;

template <class T>
int InsertionSort(T arr[], int n)
    {
	int com=0;
	for(int i=1; i<n; i++)
		{
			T key = arr[i];
			int j = i-1;

			while(j>=0)
				{
					com++;
					if(arr[j]>key)
						{
							arr[j+1]=arr[j];
							j--;
						}
					else
						break;
				}
			arr[j+1]=key;
		}
	return com;
    }

int main()
    {
	int n, com;
	cout << "Enter the number of elements ::";
	cin >> n;

	int arr[n];
	cout << "Enter the array elements ::" << endl;
	for(int i=0; i<n; i++)
		cin >> arr[i];

	com = InsertionSort<int>(arr, n);
	cout << endl << "The array after sorting ::";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	cout << endl << "Number of comparisons ::" << com;

	return 0;
    }