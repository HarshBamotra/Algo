 //Harsh Bamotra AC-1216
//Program to sort an array using insertion sort

#include <iostream>
using namespace std;

template <class T>
int InsertionSort(int n , T arr[])
	{
		T key;
		int com=0;
		for(int i=1 ; i<n ; i++)
			{
				int j=i-1;
				key = arr[i];	
				
				while(j>=0 && arr[j]>key)
					{
						arr[j+1]=arr[j];
						com++;
						j--;	
					}
				arr[j+1]=key;
				if(key>arr[j])
 					{
    						com++;
  					}
			}
		return com;
	}

int main()
    {
	int n;
	cout << "Enter the number of elemets ::";
	cin >> n;
	
	int arr[n];
	cout << "Enter the elements ::" << endl;
	for(int i=0 ; i<n ; i++)
		{
			cin >> arr[i];
		}

	cout << endl << "The array you entered ::";
	for(int i=0 ; i<n ; i++)
		{
			cout << arr[i] << " ";
		}

	int com=InsertionSort<int>(n , arr);
	
	cout << endl << "The array after sorting ::";
	for(int i=0 ; i<n ; i++)
		{
			cout << arr[i] << " ";
		}
	cout << endl << "Number of comparisons ::" << com;
	return 0;
    }